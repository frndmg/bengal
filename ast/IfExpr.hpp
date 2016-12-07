#ifndef IFEXPR_HPP
#define IFEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class IfExpr : public RValue
{
public:
    IfExpr(ptr<Expr> cond, ptr<Expr> then, ptr<Expr> els = nullptr);

private:
    ptr<Expr> m_cond;
    ptr<Expr> m_then;
    ptr<Expr> m_else;
};

} // ast namespace

#endif // IFEXPR_HPP
