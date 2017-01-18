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

///
/// \brief The Scope class
///
class Scope : public std::map<std::string, std::shared_ptr<Type> >, private std::vector<std::shared_ptr<Scope> >
{

public:
    using map::operator[];

    enum ScopeType
    {
        SimpleScope,
        BreakableScope
    };

    ///
    /// \brief Scope
    /// \param parent
    ///
    Scope(Scope* parent, ScopeType scopeType = ScopeType::SimpleScope);

    ///
    /// \brief Scope
    ///
    Scope(ScopeType scopeType = ScopeType::SimpleScope);

    ///
    /// \brief Create a new scope
    /// \return Pointer to a new empty Scope
    ///
    std::shared_ptr<Scope> beginScope();

    ///
    /// \brief Remove (if any) the last Scope created
    ///
    void endScope();

    ///
    /// \brief Get the the type (if any) that has `name` name
    /// \param name std::string
    /// \return Pointer to llvm::Type or nullptr
    ///
    mapped_type getType(const key_type& name) const;

    Scope::map& typeDef();

    mapped_type getTypeDef(const key_type& name) const;

    ScopeType getScopeType() const;

private:
    ///
    /// \brief Pointer to the parent Scope
    ///
    Scope* m_parent;

    map m_typeDef;

    ScopeType m_scopeType;
};
} // semantic namespace

#endif //BENGAL_SCOPE_HPP
