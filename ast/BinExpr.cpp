#include "BinExpr.hpp"

using namespace ast;

BinExpr::BinExpr(std::shared_ptr<Expr> lexpr, std::shared_ptr<Expr> rexpr, Operator op) :
    m_lexpr(lexpr),
    m_rexpr(rexpr),
    m_op(op)
{

}
