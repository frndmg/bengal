#include "FunctionCallExpr.hpp"

#include <memory>

using namespace ast;

#define NO_NAME_FUNCTION_ERROR "There is no function named: %s."
#define NOT_A_FUNCTION "Type [%s] is not callable."
#define INVALID_NUMBER_OF_ARGUMENTS "Invalid number of arguments. Expected %i, %i given."
#define INVALID_TYPE "Invalid type. Expected %s, %s given."

FunctionCallExpr::FunctionCallExpr(
    const std::shared_ptr<Id>& id,
    const std::shared_ptr<ExprList>& params,
    const Position& pos)
    : RValue(pos)
    , m_id(id)
    , m_params(params)
{
}

bool FunctionCallExpr::checkSemantic(Scope& scope, Report& report)
{
    bool ok = true;

    auto initial_type = scope.getTypeDef(*m_id);

    // There is no function neither type with that name
    if (not(ok = initial_type != nullptr))
        report.error(*this, NO_NAME_FUNCTION_ERROR, m_id->c_str());
    else {
        auto function_type = std::dynamic_pointer_cast<FunctionType>(initial_type);
        // Check if it is a function in fact
        if (not(ok = function_type != nullptr))
            report.error(*this, NOT_A_FUNCTION, initial_type->typeName().c_str());

        // Check the size of parameters
        else if (not(ok = function_type->size() == m_params->size()))
            report.error(*this, INVALID_NUMBER_OF_ARGUMENTS,
                function_type->size(), m_params->size());

        // Check semantic for every expression
        ok = m_params->checkSemantic(scope, report) and ok;

        // Check the types of the parameters
        auto i = m_params->begin();
        auto j = function_type->begin();

        for (; i != m_params->end(); i++, j++)
        {
            bool same;
            if ( not ( same = sameType( (*j).second, { *i } ) ) )
            {
                report.error(**i, INVALID_TYPE, (*j).second->typeName().c_str(), (*i)->type()->typeName().c_str());
                ok = same;
            }
        }
    }

    return ok;
}

FunctionCallExpr::operator std::string() const
{
    static std::string s;
    if (s == "") {
        s += "FunctionCallExpr( " + *m_id + ", { ";
        auto i = m_params->begin();
        if (i != m_params->end()) {
            s += static_cast<std::string>(**(i++));
            for (; i != m_params->end(); i++)
                s += ", " + static_cast<std::string>(**i);
        }
        s += " } )";
    }

    return s;
}
