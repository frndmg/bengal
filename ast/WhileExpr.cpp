#include "WhileExpr.hpp"

using namespace ast;

WhileExpr::WhileExpr(const std::shared_ptr<Expr>& cond,
                     const std::shared_ptr<Expr>& body,
                     const Position& pos) :
    BreakableExpr( body, pos ),
    m_cond(cond)
{
}

bool WhileExpr::checkSemantic(Scope &scope, Report &report)
{
    Scope p( &scope );
    bool valid_semantic = m_cond->checkSemantic( p, report );
    if ( not sameType( scope.getTypeDefOf( "Int32" ), { m_cond } ) )
    {
        // TODO: Report invalid type
    }
    return BreakableExpr::checkSemantic( p, report ) and valid_semantic;
}

WhileExpr::operator std::string() const
{
    return "WhileExpr( " + static_cast<std::string>( *m_cond )
            + ", " + static_cast<std::string>( *m_body )
            + " )";
}
