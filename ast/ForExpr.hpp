#ifndef FOREXPR_HPP
#define FOREXPR_HPP

#include "BreakableExpr.hpp"
#include "Id.hpp"

namespace ast
{

class ForExpr : public BreakableExpr
{
public:
    ForExpr(const std::shared_ptr<Id>& id,
            const std::shared_ptr<Expr>& begin,
            const std::shared_ptr<Expr>& end,
            const std::shared_ptr<Expr>& body,
            const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
    virtual operator std::string() const override;

private:
    std::shared_ptr<Id>   m_id;
    std::shared_ptr<Expr> m_begin;
    std::shared_ptr<Expr> m_end;
};

} // ast namespace

#endif // FOREXPR_HPP
