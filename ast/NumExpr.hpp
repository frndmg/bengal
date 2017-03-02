#ifndef NUMEXPR_HPP
#define NUMEXPR_HPP

#include "RValue.hpp"

#include <iostream>
#include <string>

namespace ast
{

class NumExpr : public RValue
{
    int m_val;

public:
    NumExpr(int val,
            const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
//    virtual void generateCode();
    virtual bool checkSemantic(Scope&, Report&) override;
    virtual operator std::string() const override;
};

} // ast namespace

#endif // NUMEXPR_HPP
