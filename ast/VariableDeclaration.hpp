#ifndef VARIABLEDECLARATION_HPP
#define VARIABLEDECLARATION_HPP

#include "DeclarationScope.hpp"
#include "Expr.hpp"
#include "Id.hpp"

namespace ast
{

class VariableDeclaration
        : public DeclarationScope
{
public:
    VariableDeclaration(
            const std::shared_ptr<Id>& id,
            const std::shared_ptr<Expr>& expr,
            const Position& pos = { 0, 0, 0, 0 } );

    VariableDeclaration(
            const std::shared_ptr<Id>& id,
            const std::shared_ptr<Id>& type,
            const std::shared_ptr<Expr>& expr,
            const Position& pos = { 0, 0, 0, 0 } );

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;
};

} // ast namespace

#endif // VARIABLEDECLARATION_HPP
