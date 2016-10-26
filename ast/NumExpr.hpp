#ifndef NUMEXPR_HPP
#define NUMEXPR_HPP

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

#include "Expr.hpp"

namespace ast
{

class NumExpr : public Expr
{
    int m_val;

public:
    NumExpr();

    virtual void generateCode();
};

} // ast namespace

#endif // NUMEXPR_HPP
