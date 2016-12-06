#include "TypeDeclaration.hpp"

using namespace ast;

TypeDeclaration::TypeDeclaration(ptr<Id> id, ptr<Id> type, bool isArray) :
    m_id(id),
    m_type(type),
    m_isArray(isArray)
{

}

TypeDeclaration::TypeDeclaration(ptr<Id> id, ptr<TypeFields> fields) :
    m_id(id),
    m_fields(fields)
{

}
