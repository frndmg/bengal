#include "NilExpr.hpp"

using namespace ast;

NilExpr::NilExpr(const Position& pos) : RValue( pos ) { }

bool NilExpr::checkSemantic(Node::Scope&, Node::Report&)
{
    setType( single_town<NilType>() );
    return true;
}

ast::NilExpr::operator std::string() const
{
    return "Nil()";
}
