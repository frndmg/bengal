#include "VariableDeclaration.hpp"

using namespace ast;

VariableDeclaration::VariableDeclaration(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<Expr>& expr,
        const Position& pos )
    : DeclarationScope( pos )
{
}

VariableDeclaration::VariableDeclaration(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<Id>& type,
        const std::shared_ptr<Expr>& expr,
        const Position& pos )
    : DeclarationScope( pos )
{
}


bool ast::VariableDeclaration::checkSemantic( Scope& scope, Report& report )
{
}
