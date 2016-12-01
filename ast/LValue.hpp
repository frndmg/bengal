#ifndef LVALUE_HPP
#define LVALUE_HPP

#include "RValue.hpp"

namespace ast
{

class LValue : public RValue
{
public:
    LValue();
};

} // ast namespace

#endif // LVALUE_HPP
