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
class Scope : public std::map<std::string, llvm::Type*>, private std::vector<std::shared_ptr<Scope> >
{

public:
    using Type = llvm::Type;
    using IntType = llvm::IntegerType;
    using ArrayType = llvm::ArrayType;
    using StructType = llvm::StructType;
    // TODO: Implement the StructType class
//    class StructType : public llvm::StructType
//    {
//    protected:
//        std::vector< std::string > m_ElementsNames;
//    public:
//        void setElementsNames(llvm::ArrayRef< llvm::StringRef > ElementsNames)
//        {
//            auto t = llvm::TypeBuilder<llvm::types::i<32>, true>::get();
////            m_ElementsNames = ElementsNames.;
//        }
//    };
    using FuntionType = llvm::FunctionType;

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
