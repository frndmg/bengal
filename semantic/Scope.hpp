//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_SCOPE_HPP
#define BENGAL_SCOPE_HPP

#include "Types.hpp"

#include <map>
#include <exception>


namespace semantic
{

/// \brief Scope class
class Scope
{

public:
    // Useful aliases
    using map = std::map<std::string, std::shared_ptr<Type> >;
    using key_type = map::key_type;
    using mapped_type = map::mapped_type;
    using value_type = map::value_type;

    using iterator = map::iterator;
    using const_iterator = map::const_iterator;

    enum ScopeType
    {
        SimpleScope = 1,
        BreakableScope = 2
    };

    /// \brief Creates a new instance of Scope class
    /// \param parent
    /// \param scope_type
    Scope( Scope* parent, ScopeType scope_type = ScopeType::SimpleScope );

    /// \brief Creates a new instance of Scope class that has no parent
    /// \param scope_type
    Scope( ScopeType scope_type = Scope::SimpleScope );

private:
    /// \brief Help function to get the type of name recursivily
    /// \param map
    /// \param name
    /// \return
    mapped_type getTypeOf(
            const map& map,
            const key_type& name ) const;

public:
    /// \brief Get the the type (if any) that has `name` name
    /// \param name
    /// \return
    mapped_type getTypeOf( const key_type& name ) const;

    /// \brief Get the type of the type named \arg name
    /// \param name
    /// \return
    mapped_type getTypeDefOf( const key_type& name ) const;

    map& typeDef();

    int scopeType() const;

private:
    /// \brief Pointer to the parent Scope
    Scope* m_parent;

    map m_typeDef;
    map m_type;

    int m_scopeType;
};
} // semantic namespace

#endif //BENGAL_SCOPE_HPP
