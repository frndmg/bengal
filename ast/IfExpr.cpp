#include "IfExpr.hpp"

using namespace ast;

IfExpr::IfExpr(const std::shared_ptr<Expr>& cond,
               const std::shared_ptr<Expr>& then,
               const std::shared_ptr<Expr>& els,
               const Position& pos) :
    RValue( pos ),
    m_cond(cond),
    m_then(then),
    m_else(els)
{

}

bool IfExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
