//
// Created by frnd on 12/30/16.
//

#include "BreakExpr.hpp"

using namespace ast;

bool BreakExpr::checkSemantic(Node::Scope &scope, Node::Report &report)
{
    switch ( scope.getScopeType() )
    {
    case sem::Scope::BreakableScope:
        return true;
    default:
        return false;
    }
}
