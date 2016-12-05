#ifndef VARIABLEDECLARATION_HPP
#define VARIABLEDECLARATION_HPP

#include "DeclarationScope.hpp"

namespace ast
{

class VariableDeclaration : public DeclarationScope
{
public:
    VariableDeclaration();
};

} // ast namespace

#endif // VARIABLEDECLARATION_HPP
