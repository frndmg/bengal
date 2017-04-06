#ifndef FIELD_HPP
#define FIELD_HPP

#include "Expr.hpp"
#include "Id.hpp"
#include "Node.hpp"

namespace ast
{

class Field
        : public Node
{
public:
    Field(
            const std::shared_ptr<Id>& id,
            const std::shared_ptr<Expr>& expr,
            const Position& pos = { 0, 0, 0, 0 } );

    const std::shared_ptr<Id> id() const
    { return m_id; }

    const std::shared_ptr<Expr> expr() const
    { return m_expr; }

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<Expr> m_expr;

    // Node interface
public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;
};

} // ast namespace

#endif // FIELD_HPP
