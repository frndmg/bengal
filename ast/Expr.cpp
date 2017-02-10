#include "Expr.hpp"

using namespace ast;

const std::shared_ptr<Expr::Type>& Expr::type() const
{
    return m_type;
}

void Expr::setType(const std::shared_ptr<Expr::Type>& type)
{
    m_type = type;
}
