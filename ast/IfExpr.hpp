#ifndef IFEXPR_HPP
#define IFEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class IfExpr : public RValue
{
public:
    IfExpr(const std::shared_ptr<Expr>& cond,
           const std::shared_ptr<Expr>& then,
           const std::shared_ptr<Expr>& els = nullptr,
           const Position& pos = { 0, 0, 0, 0 });

private:
    std::shared_ptr<Expr> m_cond;
    std::shared_ptr<Expr> m_then;
    std::shared_ptr<Expr> m_else;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // IFEXPR_HPP
