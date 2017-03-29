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

    auto new_scope = std::make_shared< Scope >( &scope );
    scopes().push_back( new_scope );

    for ( auto& x : *this )
    {
        new_scope = std::make_shared< Scope >( new_scope.get() );
        scopes().push_back( new_scope );

        ok = x->checkSemantic( *new_scope, report ) and ok;
    }
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

std::vector< std::shared_ptr< Node::Scope > >& DeclarationList::scopes()
{
    return m_scopes;
}
