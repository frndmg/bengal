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
    Field(std::shared_ptr<Id> id, std::shared_ptr<Expr> expr);

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<Expr> m_expr;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FIELD_HPP
