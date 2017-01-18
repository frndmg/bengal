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

    AssignExpr(std::shared_ptr<LValue>& lvalue, std::shared_ptr<Expr>& expr);

    virtual bool checkSemantic(Scope& scope, Report& report) override;

private:
    std::shared_ptr<LValue> m_lvalue;
    std::shared_ptr<Expr> m_expr;
};

} // ast namespace

#endif // ASSIGNEXPR_HPP
