#include "FunctionCallExpr.hpp"

using namespace ast;

#define NO_NAME_FUNCTION_ERROR "There is no function named: %s."
#define NOT_A_FUNCTION "Type [%s] is not callable."
#define INVALID_NUMBER_OF_ARGUMENTS "Invalid number of arguments. Expected %i, %i given."
#define INVALID_TYPE "Invalid type. Expected %s, %s given."

FunctionCallExpr::FunctionCallExpr(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<ExprList>& params,
        const Position& pos )
        : RValue( pos )
        , m_id( id )
        , m_params( params )
{ }

bool FunctionCallExpr::checkSemantic( Scope& scope, Report& report )
{
    bool ok = true;

    auto type = scope.getFunction( *m_id );
    if ( type == nullptr )
    {
        // There is no function in the namespace with that name.
        report.error( *this, NO_NAME_FUNCTION_ERROR, m_id->c_str() );
        ok = false;
    }
    else
    {
        auto function_type = std::dynamic_pointer_cast<FunctionType>( type );
        // Check if it is a function in fact
        if ( function_type == nullptr )
        {
            // The type is not a function in fact.
            report.error( *this, NOT_A_FUNCTION, type->typeName().c_str() );
            ok = false;
        }
        else
        {
            const auto& params = function_type->params();

            // Check the size of parameters
            if ( not params.size() == m_params->size() )
            {
                report.error( *this, INVALID_NUMBER_OF_ARGUMENTS,
                              params.size(), m_params->size() );
                ok = false;
            }

            // Check semantic for every expression
            ok = m_params->checkSemantic( scope, report ) and ok;

            // Check the types of the parameters
            auto i = m_params->begin();
            auto j = params.begin();

            for ( ; i != m_params->end(); i++, j++ )
            {
                bool same;
                if ( not( same = sameType( ( *j ).second, { *i } ) ) )
                {
                    report.error( **i,
                                  INVALID_TYPE,
                                  ( *j ).second->typeName().c_str(),
                                  ( *i )->type()->typeName().c_str() );
                    ok = same and ok;
                }
            }
        }
    }

    return ok;
}

FunctionCallExpr::operator std::string() const
{
    std::string s;
    s += "FunctionCallExpr( " + *m_id + ", { ";
    auto i = m_params->begin();
    if ( i != m_params->end() )
    {
        s += static_cast<std::string>(**( i++ ));
        for ( ; i != m_params->end(); i++ )
            s += ", " + static_cast<std::string>(**i);
    }
    s += " } )";
    return s;
}
