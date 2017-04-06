#ifndef ARRAYEXPR_HPP
#define ARRAYEXPR_HPP

#include "Id.hpp"
#include "RValue.hpp"

namespace ast
{

class ArrayExpr
        : public RValue
{
public:
    ArrayExpr(
            const std::shared_ptr<Id>& id,
            const std::shared_ptr<Expr>& size,
            const std::shared_ptr<Expr>& val,
            const Position& pos = { 0, 0, 0, 0 } );

    const std::shared_ptr<Id> id() const;

    const std::shared_ptr<Expr> size() const;

    const std::shared_ptr<Expr> value() const;

public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<Expr> m_size;
    std::shared_ptr<Expr> m_val;
};

} // ast namespace

#endif // ARRAYEXPR_HPP
