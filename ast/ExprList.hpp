#ifndef EXPRLIST_HPP
#define EXPRLIST_HPP

#include "Node.hpp"
#include "Expr.hpp"

namespace ast
{

class ExprList : public Node, private ptr_list<Expr>
{
public:
    using ptr_list<Expr>::push_back;
    using ptr_list<Expr>::begin;
    using ptr_list<Expr>::end;
    using ptr_list<Expr>::size;
    using ptr_list<Expr>::operator[];

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // EXPRLIST_HPP
