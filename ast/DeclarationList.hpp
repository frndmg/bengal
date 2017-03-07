#ifndef DECLARATIONLIST_HPP
#define DECLARATIONLIST_HPP

#include "DeclarationScope.hpp"
#include "Node.hpp"

#include <vector>

namespace ast
{

class DeclarationList
        : public Node,
          public std::vector<std::shared_ptr<DeclarationScope> >
{
public:
    DeclarationList( const Position& pos = { 0, 0, 0, 0 } );

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;
};

} // ast namespace

#endif // DECLARATIONLIST_HPP
