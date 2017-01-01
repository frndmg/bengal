#include "TypeField.hpp"

using namespace ast;

TypeField::TypeField(ptr<Id> id, ptr<Id> type) :
    m_id(id),
    m_type(type)
{

}


bool ast::TypeField::checkSemantic(Scope &scope, Report &report)
{
}