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

    BinExpr(const std::shared_ptr<Expr>& lexpr, const std::shared_ptr<Expr>& rexpr, Operator op);

private:
    std::shared_ptr<Expr> m_lexpr, m_rexpr;
    Operator m_op;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // BINEXPR_HPP
