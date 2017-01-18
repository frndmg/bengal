//
// Created by frnd on 12/30/16.
//

#include "Scope.hpp"


using namespace semantic;

Scope::Scope(Scope* parent, ScopeType scopeType) :
        map(),
        vector(),
        m_parent( parent ),
        m_scopeType( scopeType )
{
}

Scope::Scope(ScopeType scopeType) :
        map(),
        vector(),
        m_scopeType( scopeType )
{
}

std::shared_ptr<Scope> Scope::beginScope()
{
    auto newScope = std::make_shared<Scope>( this );
    vector::push_back( newScope );
    return newScope;
}

void Scope::endScope()
{
    if ( not vector::empty() )
        pop_back();
}

Scope::mapped_type Scope::getType(const key_type& name) const
{
    auto x = map::find( name );
    if ( x != map::end() )                         // Search in the current scope
        return x->second;
    else if ( m_parent )    // Search in the parent
        return m_parent->getType( name );
    return nullptr;                              // There is not such a type
}

Scope::mapped_type Scope::getTypeDef(const key_type& name) const
{
    auto x = m_typeDef.find( name );
    if ( x != m_typeDef.end() )
        return x->second;
    else if ( m_parent )
        return m_parent->getTypeDef( name );
    return nullptr;
}

Scope::ScopeType Scope::getScopeType() const
{
    return m_scopeType;
}

Scope::map& Scope::typeDef()
{
    return m_typeDef;
}

