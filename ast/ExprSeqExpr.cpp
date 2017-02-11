#include "ExprSeqExpr.hpp"

using namespace ast;

ExprSeqExpr::ExprSeqExpr(const Position& pos) : RValue( pos ), vector() { }

bool ExprSeqExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{

}
