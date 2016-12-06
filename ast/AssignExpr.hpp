#ifndef ASSIGNEXPR_HPP
#define ASSIGNEXPR_HPP

#include "Expr.hpp"
#include "LValue.hpp"

namespace ast
{

class AssignExpr : public Expr
{
public:
    AssignExpr(ptr<LValue> lvalue, ptr<Expr> expr);

private:
    ptr<LValue> m_lvalue;
    ptr<Expr> m_expr;
};

} // ast namespace

#endif // ASSIGNEXPR_HPP
