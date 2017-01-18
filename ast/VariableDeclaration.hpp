#ifndef VARIABLEDECLARATION_HPP
#define VARIABLEDECLARATION_HPP

#include "DeclarationScope.hpp"
#include "Expr.hpp"
#include "Id.hpp"

namespace ast
{

class VariableDeclaration : public DeclarationScope
{
public:
    VariableDeclaration(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr);
    VariableDeclaration(std::shared_ptr<Id> id, std::shared_ptr<Id> type, std::shared_ptr<Expr> expr);

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // VARIABLEDECLARATION_HPP
