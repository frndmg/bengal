#ifndef ARRAYEXPR_HPP
#define ARRAYEXPR_HPP

#include "Id.hpp"
#include "RValue.hpp"

namespace ast
{

class ArrayExpr : public RValue
{
public:
    ArrayExpr(ptr<Id>& id, ptr<Expr>& size, ptr<Expr>& val);

private:
    ptr<Id> m_id;
    ptr<Expr> m_size;
    ptr<Expr> m_val;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // ARRAYEXPR_HPP
