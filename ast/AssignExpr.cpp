#include "AssignExpr.hpp"

using namespace ast;

AssignExpr::~AssignExpr()
{
}

AssignExpr::AssignExpr(ptr<LValue> lvalue, ptr<Expr> expr) :
    m_lvalue(lvalue),
    m_expr(expr)
{
}

bool AssignExpr::checkSemantic(Scope& scope, Report& report)
{
    bool specific = m_lvalue->checkSemantic(scope, report) && m_expr->checkSemantic(scope, report);

}
