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
    FunctionCallExpr(ptr<Id> id, ptr<ExprList> params);

private:
    ptr<Id> m_id;
    ptr<ExprList> m_params;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FUNCTIONCALLEXPR_HPP
