#ifndef BREAKABLEEXPR_HPP
#define BREAKABLEEXPR_HPP

#include "Expr.hpp"

namespace ast
{

class BreakableExpr : public Expr
{
protected:
    std::shared_ptr<Expr> m_body;

public:
    BreakableExpr(const std::shared_ptr<Expr>& body,
                  const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
    virtual bool checkSemantic(Scope& scope, Report& report) override;
    virtual operator std::string() const override;

};

} // ast namespace

#endif // BREAKABLEEXPR_HPP
