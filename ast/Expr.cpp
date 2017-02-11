#include "Expr.hpp"

using namespace ast;

Expr::Expr(const Position& pos) : Node(pos) { }

const std::shared_ptr<Expr::Type>& Expr::type() const
{
    return m_type;
}

void Expr::setType(const std::shared_ptr<Expr::Type>& type)
{
    m_type = type;
}

bool Expr::sameType(const std::shared_ptr<Expr::Type>& type, const std::initializer_list<std::shared_ptr<Expr> >& expr_list)
{
    for (auto& x : expr_list)
        if ( not ( x->type() == type ) )
            return false;
    return true;
}

bool Expr::sameType(const std::initializer_list<std::shared_ptr<Expr> >& expr_list)
{
    auto i = expr_list.begin();
    if (i == expr_list.end()) return true;
    auto j = i + 1;
    while (j != expr_list.end())
    {
        if ( ( *i++ )->type() != ( *j++ )->type() )
            return false;
    }
    return true;
}

Expr::operator std::string() const
{
    return "Expr()";
}
