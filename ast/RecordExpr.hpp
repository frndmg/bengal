#ifndef RECORDEXPR_HPP
#define RECORDEXPR_HPP

#include "FieldList.hpp"
#include "RValue.hpp"

namespace ast
{

class RecordExpr : public RValue
{
public:
    RecordExpr(ptr<Id> id, ptr<FieldList> fields);

private:
    ptr<Id> m_id;
    ptr<FieldList> m_fields;
};

} // ast namespace

#endif // RECORDEXPR_HPP
