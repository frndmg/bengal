//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_UNARYEXPR_HPP
#define BENGAL_UNARYEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class UnaryExpr : public RValue
{
public:

    enum Operator
    {
        NEG
    };
    UnaryExpr(ptr<Expr>& expr, Operator op);

private:
    ptr<Expr> m_expr;
    Operator  m_op;
};

} // namespace ast


#endif //BENGAL_UNARYEXPR_HPP