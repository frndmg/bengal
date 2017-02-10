#include "Field.hpp"

using namespace ast;

Field::Field(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr) :
    m_id(id),
    m_expr(expr)
{

}


bool ast::Field::checkSemantic(Scope &scope, Report &report)
{
}