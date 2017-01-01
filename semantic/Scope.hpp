//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_SCOPE_HPP
#define BENGAL_SCOPE_HPP

#include <llvm/IR/Type.h>
#include <map>
#include <exception>

namespace semantic
{

///
/// \brief The Scope class
///
class Scope : public std::map< std::string, std::shared_ptr<llvm::Type> >, private std::vector< std::shared_ptr<Scope> >
{
public:
    using Type = llvm::Type;

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
    /// \brief Get the the type (if any) that has `typeName` name
    /// \param typeName
    /// \return Pointer to llvm::Type or nullptr
    ///
    const mapped_type getType( const key_type typeName ) const;

private:
    ///
    /// \brief Pointer to the parent Scope
    ///
    Scope* m_parent;
};

} // semantic namespace

#endif //BENGAL_SCOPE_HPP
