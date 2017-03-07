#ifndef TYPEDECLARATIONSCOPE_HPP
#define TYPEDECLARATIONSCOPE_HPP

#include "DeclarationScope.hpp"
#include "TypeDeclaration.hpp"

#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace ast
{

class TypeDeclarationScope
        : public DeclarationScope,
          public std::unordered_map<std::string, std::shared_ptr<TypeDeclaration> >
{
    typedef std::unordered_map<std::string, std::shared_ptr<TypeDeclaration> > unordered_map;

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;

private:
    bool hasCycle( std::set<std::string>& touched, const std::string& x );
};

} // ast namespace

#endif // TYPEDECLARATIONSCOPE_HPP
