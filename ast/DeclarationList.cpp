#include "DeclarationList.hpp"

using namespace ast;

DeclarationList::DeclarationList( const Position& pos )
        : Node( pos ), vector()
{
}

bool DeclarationList::checkSemantic(
        Node::Scope& scope,
        Node::Report& report )
{
}

DeclarationList::operator std::string() const
{
    static std::string s;

    if ( s.empty() )
    {
        s += "DeclarationList( { ";
        auto i = this->begin();
        if ( i != this->end() )
        {
            s += static_cast<std::string>( **( i++ ) );
            for ( ; i != this->end(); i++ )
                s += ", " + static_cast<std::string>( **i );
        }
        s += " } )";
    }

    return s;
}
