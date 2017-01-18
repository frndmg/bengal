#include "WhileExpr.hpp"

using namespace ast;

WhileExpr::WhileExpr(const std::shared_ptr<Expr>& cond, const std::shared_ptr<Expr>& body) :
    BreakableExpr( body ),
    m_cond(cond)
{
}

bool WhileExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{
    Scope p( &scope );
    bool valid_semantic = m_cond->checkSemantic( p, report );
    if ( not sameType( scope.getTypeDef("Int32"), { m_cond } ) )
    {
        // TODO: Report invalid type
    }
    return BreakableExpr::checkSemantic( p, report ) and valid_semantic;
}
