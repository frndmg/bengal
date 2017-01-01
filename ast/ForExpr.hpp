#ifndef FOREXPR_HPP
#define FOREXPR_HPP

#include "BreakableExpr.hpp"
#include "Id.hpp"

namespace ast
{

class ForExpr : public BreakableExpr
{
public:
    ForExpr(ptr<Id>& id, ptr<Expr>& begin, ptr<Expr>& end, ptr<Expr>& body);

private:
    ptr<Id> m_id;
    ptr<Expr> m_begin;
    ptr<Expr> m_end;
    ptr<Expr> m_body;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FOREXPR_HPP
