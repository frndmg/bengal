#include "Field.hpp"

using namespace ast;

Field::Field(ptr<Id> id, ptr<Expr> expr) :
    m_id(id),
    m_expr(expr)
{

}


bool ast::Field::checkSemantic(Scope &scope, Report &report)
{
}