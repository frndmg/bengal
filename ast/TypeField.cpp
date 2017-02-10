#include "TypeField.hpp"

using namespace ast;

TypeField::TypeField(const std::shared_ptr<Id>& id, const std::shared_ptr<Id>& type) :
    m_id(id),
    m_type(type)
{
}


bool TypeField::checkSemantic(Scope& scope, Report& report)
{
}

const std::shared_ptr<Id>& TypeField::type() const
{
    return m_type;
}

const std::shared_ptr<Id>& TypeField::id() const
{
    return m_id;
}
