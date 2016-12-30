#include "WhileExpr.hpp"

using namespace ast;

WhileExpr::WhileExpr(ptr<Expr>& cond, ptr<Expr>& body) :
    BreakableExpr(),
    m_cond(cond),
    m_body(body)
{
}
