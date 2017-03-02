#include "DeclarationList.hpp"

using namespace ast;

DeclarationList::DeclarationList( const Position& pos ) : Node( pos ), vector()
{
}

bool ast::DeclarationList::checkSemantic( Node::Scope&  scope,
                                          Node::Report& report )
{
}