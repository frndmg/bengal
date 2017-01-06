//
// Created by frnd on 12/30/16.
//

#include "UnaryExpr.hpp"


using namespace ast;

UnaryExpr::UnaryExpr(const std::shared_ptr<Expr>& expr, UnaryExpr::Operator op) :
        RValue(),
        m_expr( expr ),
        m_op( op )
{
}


bool ast::UnaryExpr::checkSemantic(Scope& scope, Report& report)
{
    bool check = m_expr->checkSemantic( scope, report );

    switch ( m_op )
    {
        case NEG:
            setType( single_town<IntType>() );
            return check and sameType( single_town<IntType>(), { m_expr } );
        default:
            return check;
    }
}
