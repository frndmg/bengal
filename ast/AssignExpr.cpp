#include "AssignExpr.hpp"

using namespace ast;

AssignExpr::~AssignExpr()
{
}

AssignExpr::AssignExpr(const std::shared_ptr<LValue> &lvalue,
                       const std::shared_ptr<Expr> &expr,
                       const Position& pos) :
    Expr( pos ),
    m_lvalue( lvalue ),
    m_expr( expr )
{
}

bool AssignExpr::checkSemantic(Scope& scope, Report& report)
{
    bool valid_semantic = m_lvalue->checkSemantic( scope, report );
    valid_semantic = m_expr->checkSemantic( scope, report ) and valid_semantic;
}

ast::AssignExpr::operator std::string() const
{
    return "AssignExpr( " + static_cast<std::string>( *m_lvalue )
            + ", " + static_cast<std::string>( *m_expr ) + " )";
}
