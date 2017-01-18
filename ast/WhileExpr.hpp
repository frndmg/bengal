#ifndef WHILEEXPR_HPP
#define WHILEEXPR_HPP

#include "BreakableExpr.hpp"

namespace ast
{

class WhileExpr : public BreakableExpr
{
public:
    WhileExpr(const ptr<Expr>& cond, const ptr<Expr>& body);

private:
    ptr<Expr> m_cond;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // WHILEEXPR_HPP
