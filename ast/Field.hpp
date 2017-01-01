#ifndef FIELD_HPP
#define FIELD_HPP

#include "Expr.hpp"
#include "Id.hpp"
#include "Node.hpp"

namespace ast
{

class Field : public Node
{
public:
    Field(ptr<Id> id, ptr<Expr> expr);

private:
    ptr<Id> m_id;
    ptr<Expr> m_expr;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FIELD_HPP
