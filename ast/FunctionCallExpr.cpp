#include "FunctionCallExpr.hpp"

using namespace ast;

FunctionCallExpr::FunctionCallExpr(std::shared_ptr<Id> id, std::shared_ptr<ExprList> params) :
    m_id(id),
    m_params(params)
{

}

bool FunctionCallExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
