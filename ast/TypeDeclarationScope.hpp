#ifndef TYPEDECLARATIONSCOPE_HPP
#define TYPEDECLARATIONSCOPE_HPP

#define TYPEDECL_TYPE_ALREADY_DEFINED "Type `%s` already defined."

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
public:
    typedef std::unordered_map< std::string, std::shared_ptr<TypeDeclaration> > map;
    typedef map::key_type key_type;
    typedef map::mapped_type mapped_type;
    typedef map::value_type value_type;

    typedef map::iterator iterator;
    typedef map::const_iterator const_iterator;

public:
    TypeDeclarationScope( const Position& = { 0, 0, 0, 0 } );

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;

private:
    bool hasCycle( std::set<std::string>& touched, const std::string& x );
};

} // ast namespace

#endif // TYPEDECLARATIONSCOPE_HPP
