#include "WhileExpr.hpp"

using namespace ast;

WhileExpr::WhileExpr(
        const std::shared_ptr<Expr>& cond,
        const std::shared_ptr<Expr>& body,
        const Position& pos )
        : BreakableExpr( body, pos )
        , m_cond( cond )
{ }

const std::shared_ptr<Expr> WhileExpr::condition() const
{ return m_cond; }

bool WhileExpr::checkSemantic( Scope& scope, Report& report )
{
    Scope p( &scope );

    auto condition = this->condition();
    bool ok = condition->checkSemantic( p, report );

    if ( not sameType( scope.getType( "int" ), { condition } ) )
    {
        report.error( *this, "The condition is not of type int" );
        ok = false;
    }
    return BreakableExpr::checkSemantic( p, report ) and ok;
}

WhileExpr::operator std::string() const
{
    return "WhileExpr( " + static_cast<std::string>( *m_cond )
           + ", " + static_cast<std::string>( *m_body )
           + " )";
}
