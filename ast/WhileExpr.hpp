#ifndef WHILEEXPR_HPP
#define WHILEEXPR_HPP

#include "BreakableExpr.hpp"

namespace ast
{

class WhileExpr : public BreakableExpr
{
public:
    WhileExpr();
};

} // ast namespace

#endif // WHILEEXPR_HPP
