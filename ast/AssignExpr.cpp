#include "AssignExpr.hpp"

using namespace ast;

AssignExpr::~AssignExpr()
{
}

AssignExpr::AssignExpr(std::shared_ptr<LValue> &lvalue, std::shared_ptr<Expr> &expr) :
    m_lvalue(lvalue),
    m_expr(expr)
{
}

bool AssignExpr::checkSemantic(Scope& scope, Report& report)
{
    bool valid_semantic = m_lvalue->checkSemantic( scope, report );
    valid_semantic = m_expr->checkSemantic( scope, report ) and valid_semantic;
}
