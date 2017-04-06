//
// Created by frnd on 12/30/16.
//

#include "Scope.hpp"

using namespace semantic;

Scope::Scope( Scope* parent, ScopeType scope_type )
        : m_parent( parent )
        , m_scope_type( parent == nullptr ? 0 : parent->scopeType() | scope_type )
{ }

Scope::Scope( Scope::ScopeType scope_type )
        : Scope( nullptr, scope_type )
{ }

int Scope::scopeType() const
{ return m_scope_type; }
