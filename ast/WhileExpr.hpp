#ifndef WHILEEXPR_HPP
#define WHILEEXPR_HPP

#include "BreakableExpr.hpp"

namespace ast
{

class WhileExpr : public BreakableExpr
{
public:
    WhileExpr(ptr<Expr>& cond, ptr<Expr>& body);

private:
    ptr<Expr> m_cond;
    ptr<Expr> m_body;
};

} // ast namespace

#endif // WHILEEXPR_HPP
