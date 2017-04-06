#include "BreakableExpr.hpp"

using namespace ast;

BreakableExpr::operator std::string() const
{
    return "BreakableExpr( " + static_cast<std::string>( *m_body ) + " )";
}

BreakableExpr::BreakableExpr(const std::shared_ptr<ast::Expr>& body,
                             const Position& pos) :
    Expr( pos ),
    m_body( body )
{
}

bool BreakableExpr::checkSemantic(Scope& scope, Report& report)
{
    Scope p( &scope, Scope::BreakableScope );
    bool ok = m_body->checkSemantic( p, report );
    setType( m_body->type() );
    return ok;
}
