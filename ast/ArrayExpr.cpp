#include "ArrayExpr.hpp"

using namespace ast;

ArrayExpr::ArrayExpr(std::shared_ptr<Id> &id, std::shared_ptr<Expr> &size, std::shared_ptr<Expr> &val) :
    m_id(id),
    m_size(size),
    m_val(val)
{

}

bool ArrayExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
