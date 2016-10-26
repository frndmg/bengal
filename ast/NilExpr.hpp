#ifndef NILEXPR_HPP
#define NILEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class NilExpr : public RValue
{
public:
    NilExpr();
};

} // ast namespace

#endif // NILEXPR_HPP
