#include "IfExpr.hpp"

using namespace ast;

IfExpr::IfExpr(
        const std::shared_ptr<Expr>& cond,
        const std::shared_ptr<Expr>& then,
        const std::shared_ptr<Expr>& els,
        const Position& pos )
        : RValue( pos )
        , m_cond( cond )
        , m_then( then )
        , m_else( els )
{ }

bool IfExpr::checkSemantic( Node::Scope& scope, Node::Report& report )
{
    bool ok = true;

    Scope if_nested_scope( &scope );

    // IF
    ok = if_()->checkSemantic( if_nested_scope, report ) and ok;

    if ( not sameType( scope.getType( "int" ), { if_() } ) )
    {
        report.error( *this, "The condition is not a number" );
        ok = false;
    }

    // THEN
    ok = then_()->checkSemantic( if_nested_scope, report ) and ok;
    auto then_type = then_()->type();

    if ( else_() != nullptr )
    {
        Scope else_nested_scope( &scope );

        // ELSE
        ok = else_()->checkSemantic( else_nested_scope, report ) and ok;

        auto else_type = else_()->type();

        if ( then_type != else_type )
            // If the type differs then none for the if
            setType( scope.getType( "none" ) );
        else
            setType( then_type );
    }
    else
        setType( then_type );

    return ok;
}
