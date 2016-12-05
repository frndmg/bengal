#ifndef FUNCTIONDECLARATIONSCOPE_HPP
#define FUNCTIONDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "FunctionDeclaration.hpp"

#include <vector>

namespace ast
{

class FunctionDeclarationScope : public DeclarationScope, private std::vector<ptr<FunctionDeclaration>>
{

public:
    FunctionDeclarationScope();

    using std::vector<ptr<FunctionDeclaration>>::push_back;
};

} // ast namespace

#endif // FUNCTIONDECLARATIONSCOPE_HPP
