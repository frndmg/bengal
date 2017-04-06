#include "AssignExpr.hpp"

using namespace ast;

AssignExpr::AssignExpr(
        const std::shared_ptr<LValue>& lvalue,
        const std::shared_ptr<Expr>& expr,
        const Position& pos )
        : Expr( pos )
        , m_lvalue( lvalue )
        , m_expr( expr )
{
}

bool AssignExpr::checkSemantic( Scope& scope, Report& report )
{
    bool lvalue_check_semantic = m_lvalue->checkSemantic( scope, report );
    bool expr_check_semantic = m_expr->checkSemantic( scope, report );
    bool ok = lvalue_check_semantic and expr_check_semantic;

    auto none_type = scope.getType( "none" );

    if ( ok and m_lvalue->type() == nullptr )
    {
        // If the variable is new and the expression is well.
        auto expr_type = m_expr->type();
        if ( expr_type == none_type or expr_type == nullptr )
        {
            report.error( *m_expr, "Expression is not an rvalue" );
            ok = false;
        }
        else
        {
            // Creates a new variable.
            m_lvalue->setType( expr_type );
            scope.addVariable( *m_lvalue->id(), expr_type );
        }
    }
    else if ( ok )
    {
        // If the variable is not new.
        auto expr_type = m_expr->type();
        if ( expr_type != m_lvalue->type() )
        {
            report.error( *this, "The type of lvalue and expression mismatch" );
            ok = false;
        }
    }

    // This work against multiple assignations.
    setType( none_type );

    return ok;
}

ast::AssignExpr::operator std::string() const
{
    return "AssignExpr( "
           + static_cast<std::string>( *m_lvalue ) + ", "
           + static_cast<std::string>( *m_expr ) + " )";
}
