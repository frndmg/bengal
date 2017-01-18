#include "LetExpr.hpp"

using namespace ast;

LetExpr::LetExpr(std::shared_ptr<DeclarationList> scope, std::shared_ptr<ExprSeqExpr> expr_seq) :
    m_scope(scope),
    m_expr_seq(expr_seq)
{

}

bool LetExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
