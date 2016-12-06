#include "AssignExpr.hpp"

using namespace ast;

AssignExpr::AssignExpr(ptr<LValue> lvalue, ptr<Expr> expr) :
    m_lvalue(lvalue),
    m_expr(expr)
{

}
