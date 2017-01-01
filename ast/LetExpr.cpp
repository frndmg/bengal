#include "LetExpr.hpp"

using namespace ast;

LetExpr::LetExpr(ptr<DeclarationList> scope, ptr<ExprSeqExpr> expr_seq) :
    m_scope(scope),
    m_expr_seq(expr_seq)
{

}

bool LetExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
