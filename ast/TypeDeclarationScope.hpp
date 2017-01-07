#ifndef TYPEDECLARATIONSCOPE_HPP
#define TYPEDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "TypeDeclaration.hpp"

#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace ast
{

class TypeDeclarationScope :
        public DeclarationScope, public std::unordered_map<std::string, std::shared_ptr<TypeDeclaration> >
{
    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;

private:
    bool hasCycle(std::unordered_set<std::string>& touched, const std::string& x);
};

} // ast namespace

#endif // TYPEDECLARATIONSCOPE_HPP
