#include "ForExpr.hpp"

using namespace ast;

ForExpr::ForExpr(ptr<Id>& id, ptr<Expr>& begin, ptr<Expr>& end, ptr<Expr>& body) :
    BreakableExpr( m_body ),
    m_id(id),
    m_begin(begin),
    m_end(end)
{
}

bool ForExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
