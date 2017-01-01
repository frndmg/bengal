//
// Created by frnd on 12/30/16.
//

#include "UnaryExpr.hpp"

using namespace ast;

UnaryExpr::UnaryExpr(ptr<Expr> &expr, UnaryExpr::Operator op) :
    RValue(),
    m_expr(expr),
    m_op(op)
{
}


bool ast::UnaryExpr::checkSemantic(Scope &scope, Report &report)
{
}