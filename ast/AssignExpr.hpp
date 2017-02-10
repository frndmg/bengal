#ifndef ASSIGNEXPR_HPP
#define ASSIGNEXPR_HPP

#include "Expr.hpp"
#include "LValue.hpp"

namespace ast
{

class AssignExpr : public Expr
{
public:
    virtual ~AssignExpr();

    AssignExpr(const std::shared_ptr<LValue>& lvalue,
               const std::shared_ptr<Expr>& expr);

    // Node interface
public:
    virtual bool checkSemantic(Scope& scope, Report& report) override;

private:
    std::shared_ptr<LValue> m_lvalue;
    std::shared_ptr<Expr> m_expr;
};

} // ast namespace

#endif // ASSIGNEXPR_HPP
