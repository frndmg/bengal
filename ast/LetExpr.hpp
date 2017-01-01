#ifndef LETEXPR_HPP
#define LETEXPR_HPP

#include "RValue.hpp"
#include "DeclarationList.hpp"
#include "ExprSeqExpr.hpp"

namespace ast
{

class LetExpr : public RValue
{
public:
    LetExpr(ptr<DeclarationList> scope, ptr<ExprSeqExpr> expr_seq);

private:
    ptr<DeclarationList> m_scope;
    ptr<ExprSeqExpr> m_expr_seq;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // LETEXPR_HPP
