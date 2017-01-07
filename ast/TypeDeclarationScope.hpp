#ifndef TYPEDECLARATIONSCOPE_HPP
#define TYPEDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "TypeDeclaration.hpp"

#include <vector>
#include <unordered_map>


namespace ast
{

class TypeDeclarationScope :
        public DeclarationScope, public std::unordered_map<std::string, std::shared_ptr<TypeDeclaration> >
{
    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // TYPEDECLARATIONSCOPE_HPP
