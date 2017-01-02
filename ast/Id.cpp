#include "Id.hpp"

using namespace ast;

Id::Id(const std::string &id) :
    m_id(id)
{
}

std::string Id::id() const
{
    return m_id;
}
