#ifndef WHILEEXPR_HPP
#define WHILEEXPR_HPP

#include "BreakableExpr.hpp"

namespace ast
{

class WhileExpr
        : public BreakableExpr
{
public:
    WhileExpr(
            const std::shared_ptr<Expr>& cond,
            const std::shared_ptr<Expr>& body,
            const Position& pos = { 0, 0, 0, 0 } );

    const std::shared_ptr<Expr> condition() const;

private:
    std::shared_ptr<Expr> m_cond;

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;
};

} // ast namespace

#endif // WHILEEXPR_HPP
