#ifndef NUMEXPR_HPP
#define NUMEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class NumExpr : public RValue
{
    int m_val;

public:
    NumExpr(int val) :
        RValue()
      , m_val(val)
    {
    }

//    virtual void generateCode();

    // Node interface
public:
    virtual bool checkSemantic(Scope&, Report&) override { return true; }
};

} // ast namespace

#endif // NUMEXPR_HPP
