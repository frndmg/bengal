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
    VariableDeclaration(ptr<Id> id, ptr<Expr> expr);
    VariableDeclaration(ptr<Id> id, ptr<Id> type, ptr<Expr> expr);

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // VARIABLEDECLARATION_HPP
