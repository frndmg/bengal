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
    Scope p( &scope );
    bool valid_semantic = m_begin->checkSemantic( p, report );
    valid_semantic      = m_end->checkSemantic( p, report ) and valid_semantic;
    if ( not sameType( scope.getTypeDef("Int32"), { m_begin, m_end } ) )
    {
        // TODO: Report error
        valid_semantic = false;
    }
    return BreakableExpr::checkSemantic( p, report ) and valid_semantic;
}
