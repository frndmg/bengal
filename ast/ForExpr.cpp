#include "ForExpr.hpp"

using namespace ast;

ForExpr::ForExpr(const std::shared_ptr<Id>& id,
                 const std::shared_ptr<Expr>& begin,
                 const std::shared_ptr<Expr>& end,
                 const std::shared_ptr<Expr>& body,
                 const Position& pos) :
    BreakableExpr( body, pos ),
    m_id(id),
    m_begin(begin),
    m_end(end)
{
}

bool ForExpr::checkSemantic(Scope &scope, Report &report)
{
    Scope p( &scope );
    bool valid_semantic = m_begin->checkSemantic( p, report );
    valid_semantic      = m_end->checkSemantic( p, report ) and valid_semantic;
    if ( not sameType( scope.getTypeDefOf( "Int32" ), { m_begin, m_end } ) )
    {
        // TODO: Report error
        valid_semantic = false;
    }
    return BreakableExpr::checkSemantic( p, report ) and valid_semantic;
}

ast::ForExpr::operator std::string() const
{
    return "ForExpr( " + static_cast<std::string>( *m_id )
            + ", " + static_cast<std::string>( *m_begin )
            + ", " + static_cast<std::string>( *m_end )
            + ", " + static_cast<std::string>( *m_body )
            + " )";
}
