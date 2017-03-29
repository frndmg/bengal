#include "LetExpr.hpp"

using namespace ast;

LetExpr::LetExpr(
        const std::shared_ptr<DeclarationList>& scope,
        const std::shared_ptr<ExprSeqExpr>& expr_seq,
        const Position& pos )
        : RValue( pos )
        , m_scope( scope )
        , m_expr_seq( expr_seq )
{
}

bool LetExpr::checkSemantic( Scope& scope, Report& report )
{
    bool ok( true );

    // The execution of the let expression occurs in a new scope
    Scope new_scope( &scope );
    ok = this->scope()->checkSemantic( new_scope, report ) and ok;
    // TODO: Get the most deep scope, something like
    // new_scope = scope()->deepScope();
    ok = this->expr_seq()->checkSemantic( new_scope, report ) and ok;
    // at this time new_scope is gone

    // If the let expression returns any value
    const auto& ret_type = this->expr_seq()->type();
    if ( ret_type != nullptr )
    {
        // If the type of the let's return isn't in the above scope then error
        const auto& ret_type_name = ret_type->typeName();
        if ( scope.getTypeDefOf( ret_type_name ) == nullptr )
        {
            ok = false;
            report.error( *this, "The type `%s` does not exist in the current scope.", ret_type_name.c_str() );
        }
    }
    return ok;
}

LetExpr::operator std::string() const
{
    return "LetExpr( "
           + static_cast<std::string>( *scope() ) + ", "
           + static_cast<std::string>( *expr_seq() ) + " )";
}

const std::shared_ptr<DeclarationList>& LetExpr::scope() const
{
    return m_scope;
}

const std::shared_ptr<ExprSeqExpr>& LetExpr::expr_seq() const
{
    return m_expr_seq;
}
