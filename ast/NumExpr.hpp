#ifndef NUMEXPR_HPP
#define NUMEXPR_HPP

#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>

#include "RValue.hpp"

namespace ast
{

class NumExpr : public RValue
{
    long long m_val;

public:
    NumExpr() = default;

    NumExpr(long long val) :
        RValue()
      , m_val(val)
    {
    }

//    virtual void generateCode();
};

} // ast namespace

#endif // NUMEXPR_HPP
