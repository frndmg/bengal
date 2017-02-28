//
// Created by frnd on 12/30/16.
//

#include "Scope.hpp"

using namespace semantic;

Scope::Scope( Scope* parent, ScopeType scope_type )
        : m_parent( parent )
        , m_scopeType( parent == nullptr ? 0 : parent->scopeType() | scope_type )
{
}

Scope::Scope( Scope::ScopeType scope_type )
        : Scope( nullptr, scope_type )
{
}

Scope::mapped_type Scope::getTypeOf( const Scope::map& map, const Scope::key_type& name ) const
{
    // Look in the current  scope
    auto x = map.find( name );
    if ( x != map.end() )
        return x->second;
    else if ( m_parent )
        // Look in the parent
        return m_parent->getTypeOf( map, name );
    return nullptr;
}

Scope::mapped_type Scope::getTypeOf( const key_type& name ) const
{
    return getTypeOf( m_type, name );
}

Scope::mapped_type Scope::getTypeDefOf( const key_type& name ) const
{
    return getTypeOf( m_typeDef, name );
}

int Scope::scopeType() const
{
    return m_scopeType;
}

Scope::map& Scope::typeDef()
{
    return m_typeDef;
}

