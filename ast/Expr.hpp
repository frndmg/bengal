#ifndef EXPR_HPP
#define EXPR_HPP

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include "Node.hpp"

namespace ast
{

static std::unique_ptr<llvm::Module> *TheModule;
static llvm::IRBuilder<> Builder(llvm::getGlobalContext());
static std::map<std::string, llvm::Value *> NamedValues;

class Expr : public Node
{
public:
    virtual ~Expr();
};

} // namespace ast

#endif // EXPR_HPP
