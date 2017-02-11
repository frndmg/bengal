#ifndef FUNCTIONCALLEXPR_HPP
#define FUNCTIONCALLEXPR_HPP

#include "ExprList.hpp"
#include "Id.hpp"
#include "RValue.hpp"

namespace ast
{

class FunctionCallExpr : public RValue
{
public:
    FunctionCallExpr(const std::shared_ptr<Id>& id,
                     const std::shared_ptr<ExprList>& params,
                     const Position& pos = { 0, 0, 0, 0 });

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<ExprList> m_params;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FUNCTIONCALLEXPR_HPP
