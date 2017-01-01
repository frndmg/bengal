#include "VariableDeclaration.hpp"

using namespace ast;

ast::VariableDeclaration::VariableDeclaration(ptr<ast::Id> id, ptr<ast::Expr> expr)
{

}

VariableDeclaration::VariableDeclaration(ptr<Id> id, ptr<Id> type, ptr<Expr> expr)
{

}


bool ast::VariableDeclaration::checkSemantic(Scope &scope, Report &report)
{
}