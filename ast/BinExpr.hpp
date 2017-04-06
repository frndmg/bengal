#ifndef BINEXPR_HPP
#define BINEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class BinExpr
        : public RValue
{
public:
    enum Operator
    {
        EQUAL, NEQUAL, GREATER, LESS, GEQ, LEQ, AND, OR, MUL, DIV, ADD, SUB
    };

    BinExpr(
            const std::shared_ptr<Expr>& lexpr,
            const std::shared_ptr<Expr>& rexpr,
            Operator op,
            const Position& pos = { 0, 0, 0, 0 } );

public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;

private:
    std::shared_ptr<Expr> m_lexpr, m_rexpr;
    Operator m_op;
};

} // ast namespace

#endif // BINEXPR_HPP
