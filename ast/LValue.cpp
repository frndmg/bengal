#include "LValue.hpp"

using namespace ast;

LValue::LValue(ptr<Id> id) :
    m_id(id)
{

}

LValue::LValue(ptr<Id> id, ptr<LValue> field) :
    m_id(id),
    m_field(field)
{

}

LValue::LValue(ptr<Id> id, ptr<Expr> index) :
    m_id(id),
    m_index(index)
{

}

bool LValue::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
