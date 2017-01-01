#ifndef FUNCTIONDECLARATIONSCOPE_HPP
#define FUNCTIONDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "FunctionDeclaration.hpp"

namespace ast
{

class FunctionDeclarationScope : public DeclarationScope, private ptr_list<FunctionDeclaration>
{

public:
    using ptr_list<FunctionDeclaration>::push_back;
    using ptr_list<FunctionDeclaration>::begin;
    using ptr_list<FunctionDeclaration>::end;
    using ptr_list<FunctionDeclaration>::size;
    using ptr_list<FunctionDeclaration>::operator[];

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FUNCTIONDECLARATIONSCOPE_HPP
