#include "RecordExpr.hpp"

using namespace ast;

RecordExpr::RecordExpr(std::shared_ptr<Id> id, std::shared_ptr<FieldList> fields) :
    m_id(id),
    m_fields(fields)
{

}


bool ast::RecordExpr::checkSemantic(Scope &scope, Report &report)
{
}