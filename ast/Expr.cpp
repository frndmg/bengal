#include "Expr.hpp"

using namespace ast;

Expr::Type* Expr::type() const
{
    return m_type;
}

void Expr::setType(Type* type)
{
    m_type = type;
}
