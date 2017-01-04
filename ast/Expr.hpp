#ifndef EXPR_HPP
#define EXPR_HPP

//#include <llvm/IR/Value.h>
//#include <llvm/IR/IRBuilder.h>
//#include <llvm/IR/Module.h>

#include "Node.hpp"

namespace ast
{

//static std::unique_ptr<llvm::Module> *MainModule;
//static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
//static std::map<std::string, llvm::Value *> NamedValues;

class Expr : public Node
{
protected:
    using Type = Scope::Type;
    using IntType = Scope::IntType;
    using ArrayType = Scope::ArrayType;
    using StructType = Scope::StructType;
    using FunctionType = Scope::FuntionType;

    Type* type() const;
    void setType(Type* type);

private:
    Type* m_type;
};

} // namespace ast

#endif // EXPR_HPP
