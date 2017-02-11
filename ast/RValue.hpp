#ifndef RVALUE_HPP
#define RVALUE_HPP

#include "Expr.hpp"

namespace ast
{

class RValue : public Expr
{
public:
    RValue(const Position& pos);
};

} // ast namespace

#endif // RVALUE_HPP
