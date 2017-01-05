//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_SCOPE_HPP
#define BENGAL_SCOPE_HPP

#include "Types.hpp"

#include <llvm/IR/Type.h>
#include <llvm/IR/TypeBuilder.h>
#include <llvm/IR/DerivedTypes.h>
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
    ///
    /// \brief Scope
    /// \param parent
    ///
    Scope(Scope* parent);

    ///
    /// \brief Scope
    ///
    Scope();

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

private:
    ///
    /// \brief Pointer to the parent Scope
    ///
    Scope* m_parent;
};

} // semantic namespace

#endif //BENGAL_SCOPE_HPP
