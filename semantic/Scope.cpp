//
// Created by frnd on 12/30/16.
//

#include "Scope.hpp"

using namespace semantic;

Scope::Scope(Scope *parent) :
    map(),
    vector(),
    m_parent(parent)
{
}

Scope::Scope() :
    map(),
    vector()
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
    if (not vector::empty())
        pop_back();
}

Scope::mapped_type Scope::getType(const Scope::key_type name) const
{
    auto x = map::find( name );
    if (x != map::end())                         // Search in the current scope
        return x->second;
    else if ( m_parent )    // Search in the parent
        return m_parent->getType( name );
    return nullptr;                              // There is not such a type
}
