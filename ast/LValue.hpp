#ifndef LVALUE_HPP
#define LVALUE_HPP

#include "Id.hpp"
#include "RValue.hpp"

namespace ast
{

class LValue : public RValue
{
public:
    LValue(ptr<Id> id);
    LValue(ptr<Id> id, ptr<LValue> field);
    LValue(ptr<Id> id, ptr<Expr> index);

private:
    ptr<Id> m_id;
    ptr<LValue> m_field;
    ptr<Expr> m_index;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // LVALUE_HPP
