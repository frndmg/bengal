#include "FunctionCallExpr.hpp"

using namespace ast;

FunctionCallExpr::FunctionCallExpr(ptr<Id> id, ptr<ExprList> params) :
    m_id(id),
    m_params(params)
{

}
