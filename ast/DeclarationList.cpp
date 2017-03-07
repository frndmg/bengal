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
    // Only have to check that all the declaration scopes has been
    // declared well semantically.
    bool ok( true );
    for ( auto& x : *this )
        ok = x->checkSemantic( scope, report ) and ok;
    return ok;
}

DeclarationList::operator std::string() const
{
    static std::string s;

    if ( s.empty() )
    {
        s += "DeclarationList( ";
        auto i = this->begin();
        if ( i != this->end() )
        {
            s += static_cast<std::string>( **( i++ ) );
            for ( ; i != this->end(); i++ )
                s += ", " + static_cast<std::string>( **i );
        }
        s += " )";
    }

    return s;
}
