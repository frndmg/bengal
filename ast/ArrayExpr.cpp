#include "ArrayExpr.hpp"

using namespace ast;

ArrayExpr::ArrayExpr(ptr<Id> id, ptr<Expr> size, ptr<Expr> val) :
    m_id(id),
    m_size(size),
    m_val(val)
{

}
