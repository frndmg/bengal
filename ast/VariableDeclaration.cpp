#include "VariableDeclaration.hpp"

using namespace ast;

ast::VariableDeclaration::VariableDeclaration(std::shared_ptr<ast::Id> id, std::shared_ptr<ast::Expr> expr)
{

}

VariableDeclaration::VariableDeclaration(std::shared_ptr<Id> id, std::shared_ptr<Id> type, std::shared_ptr<Expr> expr)
{

}


bool ast::VariableDeclaration::checkSemantic(Scope &scope, Report &report)
{
}