#include "IfExpr.hpp"

using namespace ast;

IfExpr::IfExpr(ptr<Expr> cond, ptr<Expr> then, ptr<Expr> els) :
    m_cond(cond),
    m_then(then),
    m_else(els)
{

}
