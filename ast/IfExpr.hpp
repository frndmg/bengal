#ifndef IFEXPR_HPP
#define IFEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class IfExpr : public RValue
{
public:
    IfExpr(std::shared_ptr<Expr> cond, std::shared_ptr<Expr> then, std::shared_ptr<Expr> els = nullptr);

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
