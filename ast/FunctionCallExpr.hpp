#ifndef FUNCTIONCALLEXPR_HPP
#define FUNCTIONCALLEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class FunctionCallExpr : public RValue
{
public:
    FunctionCallExpr();
};

} // ast namespace

#endif // FUNCTIONCALLEXPR_HPP
