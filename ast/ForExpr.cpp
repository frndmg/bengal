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
    bool ok = m_begin->checkSemantic( p, report );
    ok = m_end->checkSemantic( p, report ) and ok;
    if ( not sameType( scope.getType( "int" ), { m_begin, m_end } ) )
    {
        report.error( *this, "Bounds of the for must be numbers" );
        ok = false;
    }
    return BreakableExpr::checkSemantic( p, report ) and ok;
}

ast::ForExpr::operator std::string() const
{
    return "ForExpr( " + static_cast<std::string>( *m_id )
            + ", " + static_cast<std::string>( *m_begin )
            + ", " + static_cast<std::string>( *m_end )
            + ", " + static_cast<std::string>( *m_body )
            + " )";
}
