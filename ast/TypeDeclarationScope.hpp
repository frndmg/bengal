#ifndef TYPEDECLARATIONSCOPE_HPP
#define TYPEDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "TypeDeclaration.hpp"

#include <vector>

namespace ast
{

class TypeDeclarationScope : public DeclarationScope, private std::vector<ptr<TypeDeclaration>>
{
public:
    TypeDeclarationScope();

    using std::vector<ptr<TypeDeclaration>>::push_back;
};

} // ast namespace

#endif // TYPEDECLARATIONSCOPE_HPP
