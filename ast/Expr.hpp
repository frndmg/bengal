#ifndef EXPR_HPP
#define EXPR_HPP

//#include <llvm/IR/Value.h>
//#include <llvm/IR/IRBuilder.h>
//#include <llvm/IR/Module.h>

#include "Node.hpp"

namespace sem = semantic;

namespace ast
{

class Expr : public Node
{
public:
    Expr(const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
    virtual operator std::string() const override;

protected:
    using Type = sem::Type;
    using IntType = sem::IntType;
    using StringType = sem::StringType;
    using NilType = sem::NilType;
    using ArrayType = sem::ArrayType;
    using StructType = sem::StructType;
    using FunctionType = sem::FunctionType;
    using AliasType = sem::AliasType;
    using Procedure = sem::ProcedureType;
    using NoneType = sem::NoneType;

    // Type property
    const std::shared_ptr<Type>& type() const;
    void setType(const std::shared_ptr<Type>& type);

    ///
    /// \brief Compare with a specific type
    /// \param type
    /// \param expr_list
    /// \return
    ///
    static bool sameType(const std::shared_ptr<Type>& type,
                         const std::initializer_list<std::shared_ptr<Expr> >& expr_list);

    ///
    /// \brief Check that all have the same type
    /// \param expr_list
    /// \return
    ///
    static bool sameType(const std::initializer_list<std::shared_ptr<Expr> >& expr_list );

private:
    std::shared_ptr<Type> m_type;
};

} // namespace ast

#endif // EXPR_HPP
