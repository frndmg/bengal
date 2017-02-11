#ifndef RECORDEXPR_HPP
#define RECORDEXPR_HPP

#include "FieldList.hpp"
#include "RValue.hpp"

namespace ast
{

class RecordExpr : public RValue
{
public:
    RecordExpr(const std::shared_ptr<Id>& id,
               const std::shared_ptr<FieldList>& fields,
               const Position& pos = { 0, 0, 0, 0 });

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<FieldList> m_fields;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // RECORDEXPR_HPP
