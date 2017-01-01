#ifndef TYPEDECLARATIONSCOPE_HPP
#define TYPEDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "TypeDeclaration.hpp"

#include <vector>

namespace ast
{

class TypeDeclarationScope : public DeclarationScope, private ptr_list<TypeDeclaration>
{
public:
    using ptr_list<TypeDeclaration>::push_back;
    using ptr_list<TypeDeclaration>::begin;
    using ptr_list<TypeDeclaration>::end;
    using ptr_list<TypeDeclaration>::size;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // TYPEDECLARATIONSCOPE_HPP
