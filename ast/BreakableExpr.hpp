#ifndef BREAKABLEEXPR_HPP
#define BREAKABLEEXPR_HPP

#include "Expr.hpp"

namespace ast
{

class BreakableExpr : public Expr
{
protected:
    std::shared_ptr<Expr> m_body;

public:
    BreakableExpr(const std::shared_ptr<Expr>& body) :
        Expr(),
        m_body( body )
    {
    }

    // Node interface
    virtual bool checkSemantic(Scope& scope, Report& report) override
    {
        Scope p( &scope, sem::Scope::BreakableScope );
        return m_body->checkSemantic( p, report );
    }
};

} // ast namespace

#endif // BREAKABLEEXPR_HPP
