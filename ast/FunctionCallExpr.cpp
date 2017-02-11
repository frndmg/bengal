#include "FunctionCallExpr.hpp"

using namespace ast;

FunctionCallExpr::FunctionCallExpr(const std::shared_ptr<Id>& id,
                                   const std::shared_ptr<ExprList>& params,
                                   const Position& pos) :
    RValue( pos ),
    m_id(id),
    m_params(params)
{

}

bool FunctionCallExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
