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

}

LetExpr::operator std::string() const
{
    return "LetExpr( "
           + static_cast<std::string>( *m_scope ) + ", "
           + static_cast<std::string>( *m_expr_seq ) + " )";
}

const std::shared_ptr<DeclarationList>& LetExpr::scope() const
{
    return m_scope;
}

const std::shared_ptr<ExprSeqExpr>& LetExpr::expr_seq() const
{
    return m_expr_seq;
}
