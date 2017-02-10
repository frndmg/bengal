#ifndef FOREXPR_HPP
#define FOREXPR_HPP

#include "BreakableExpr.hpp"
#include "Id.hpp"

namespace ast
{

class ForExpr : public BreakableExpr
{
public:
    ForExpr(std::shared_ptr<Id>& id, std::shared_ptr<Expr>& begin, std::shared_ptr<Expr>& end, std::shared_ptr<Expr>& body);

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;

private:
    std::shared_ptr<Id>   m_id;
    std::shared_ptr<Expr> m_begin;
    std::shared_ptr<Expr> m_end;
};

} // ast namespace

#endif // FOREXPR_HPP
