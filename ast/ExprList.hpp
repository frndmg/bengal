#ifndef EXPRLIST_HPP
#define EXPRLIST_HPP

#include "Node.hpp"
#include "Expr.hpp"

namespace ast
{

class ExprList : public Node, public std::vector<std::shared_ptr<Expr> >
{
public:
    ExprList(const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
    virtual operator std::string() const override;
};

} // ast namespace

#endif // EXPRLIST_HPP
