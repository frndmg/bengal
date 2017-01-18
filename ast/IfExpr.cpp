#include "IfExpr.hpp"

using namespace ast;

IfExpr::IfExpr(std::shared_ptr<Expr> cond, std::shared_ptr<Expr> then, std::shared_ptr<Expr> els) :
    m_cond(cond),
    m_then(then),
    m_else(els)
{

}

bool IfExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
