#include "RecordExpr.hpp"

using namespace ast;

RecordExpr::RecordExpr(ptr<Id> id, ptr<FieldList> fields) :
    m_id(id),
    m_fields(fields)
{

}


bool ast::RecordExpr::checkSemantic(Scope &scope, Report &report)
{
}