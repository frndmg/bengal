#ifndef BINEXPR_HPP
#define BINEXPR_HPP

//#include <memory>

#include "RValue.hpp"

namespace ast
{

class BinExpr : public RValue
{
public:
    enum Operator
    {
        EQUAL, NEQUAL, GREATER, LESS, GEQ, LEQ, AND, OR, MUL, DIV, ADD, SUB
    };

    BinExpr(std::shared_ptr<Expr> lexpr, std::shared_ptr<Expr> rexpr, Operator op);

private:
    std::shared_ptr<Expr> m_lexpr, m_rexpr;
    Operator m_op;
};

} // ast namespace

#endif // BINEXPR_HPP
