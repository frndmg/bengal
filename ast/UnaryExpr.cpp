//
// Created by frnd on 12/30/16.
//

#include "UnaryExpr.hpp"


using namespace ast;

UnaryExpr::UnaryExpr(const std::shared_ptr<Expr>& expr, UnaryExpr::Operator op, const Position& pos) :
        RValue( pos ),
        m_expr( expr ),
        m_op( op )
{
}

bool UnaryExpr::checkSemantic(Scope& scope, Report& report)
{
    bool ok = m_expr->checkSemantic( scope, report );

    auto int_type = scope.getTypeDef( "int" );

    switch ( m_op )
    {
    case NEG:
        if ( not ( ok = sameType( int_type, { m_expr } ) ) )
        {
            report.error(*this,
                         "The expression is not of type int. Note: [type = %s]",
                         m_expr->type()->typeName().c_str());
        }
        break;
    default:
        ok = false;
    }
    if ( ok )
        setType( int_type );

    return ok;
}

ast::UnaryExpr::operator std::string() const
{
    static char ops[] { '-' };
    return "UnaryExpr( " + static_cast<std::string>( *m_expr )
            + ", " + ops[m_op] + " )";
}
