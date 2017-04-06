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

    /// \brief Valid values of the scope type.
    enum ScopeType
    {
        SimpleScope = 1,
        BreakableScope = 2
    };

    /// \brief Creates a new instance of Scope class.
    /// \param parent Parent of the scope.
    /// \param scope_type Type of the scope.
    Scope( Scope* parent, ScopeType scope_type = ScopeType::SimpleScope );

    /// \brief Creates a new instance of Scope class that has no parent.
    /// \param scope_type Type of the scope.
    Scope( ScopeType scope_type = Scope::SimpleScope );

    /// \brief Gets the type of the scope.
    /// \return The type of the scope.
    int scopeType() const;

public:
    /// \brief Returns a reference to the given namespace.
    /// \param namespace_name The name of the namespace.
    /// \return A reference to the namespace named namespace_name.
    map& operator[]( const std::string& namespace_name )
    { return *m_scope_types.at( namespace_name ); }

private:
    bool __add(
            const std::string& namespace_name,
            const key_type& name,
            const mapped_type& type )
    {
        map& scope = ( *this )[namespace_name];
        return scope.insert( { name, type } ).second;
    }

    mapped_type __get(
            const std::string& namespace_name,
            const key_type& name )
    {
        map& scope = ( *this )[namespace_name];
        auto it = scope.find( name );
        if ( it != scope.end() )
            return it->second;
        else if ( m_parent )
            return m_parent->__get( namespace_name, name );
        return nullptr;
    }

public:
    /// \brief Adds a new type to the type namespace in the current scope.
    /// \param type_name The name of the new type.
    /// \param type_definition The type of the new type.
    /// \return true if the type was well inserted, false otherwise.
    bool addType(
            const key_type& type_name,
            const mapped_type& type_definition )
    { return __add( "type", type_name, type_definition ); }

    /// \brief Gets the type named name.
    /// \param name The name of the type.
    /// \return The type of the type of nullptr if the type does not exist.
    mapped_type getType( const key_type& name )
    { return __get( "type", name ); }

    /// \brief Adds a variable to the variable namespace in the current scope.
    /// \param variable_name The name of the variable.
    /// \param variable_type The type of the new variable.
    /// \return true if the variable was well inserted, false otherwise.
    bool addVariable(
            const key_type& variable_name,
            const mapped_type& variable_type )
    { return __add( "variable", variable_name, variable_type ); }

    /// \brief Gets the variable named name.
    /// \param name The name of the variable.
    /// \return The type of the variable or nullptr if the variable does not
    ///         exist.
    mapped_type getVariable( const key_type& name )
    { return __get( "variable", name ); }

    /// \brief Adds a new function to the function namespace in the current scope.
    /// \param function_name The name of the new function.
    /// \param function_type The type of the new function.
    /// \return true if the variable was well inserted, false otherwise.
    bool addFunction(
            const key_type& function_name,
            const mapped_type& function_type )
    { return __add( "function", function_name, function_type ); }

    /// \brief Gets the function named name.
    /// \param name The name of the function.
    /// \return The type of the function of nullptr if the function does not
    ///         exist.
    mapped_type getFunction( const key_type& name )
    { return __get( "function", name ); }

private:
    /// \brief Pointer to the parent Scope
    Scope* m_parent;

    /// \brief Maps to every namespace of the scope
    map m_variable_or_function_scope;
    map m_type_definition_scope;

    /// \brief Namespaces.
    std::map<std::string, map*> m_scope_types = {
            { "variable", &m_variable_or_function_scope },
            { "function", &m_variable_or_function_scope },
            { "type",     &m_type_definition_scope }
    };

    int m_scope_type;
};
} // semantic namespace

#endif //BENGAL_SCOPE_HPP
