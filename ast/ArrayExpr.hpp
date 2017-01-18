#ifndef ARRAYEXPR_HPP
#define ARRAYEXPR_HPP

#include "Id.hpp"
#include "RValue.hpp"

namespace ast
{

class ArrayExpr : public RValue
{
public:
    ArrayExpr(std::shared_ptr<Id>& id, std::shared_ptr<Expr>& size, std::shared_ptr<Expr>& val);

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<Expr> m_size;
    std::shared_ptr<Expr> m_val;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // ARRAYEXPR_HPP
