#ifndef DECLARATIONSCOPE_HPP
#define DECLARATIONSCOPE_HPP

#include "Node.hpp"

namespace ast
{

class DeclarationScope
        : public Node
{
protected:
    DeclarationScope( const Position& pos );
};

} // ast namespace

#endif // DECLARATIONSCOPE_HPP
