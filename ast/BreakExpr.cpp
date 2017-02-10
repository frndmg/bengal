//
// Created by frnd on 12/30/16.
//

#include "BreakExpr.hpp"

using namespace ast;

bool BreakExpr::checkSemantic(Scope &scope, Report &report)
{
    switch ( scope.getScopeType() )
    {
    case Scope::BreakableScope:
        return true;
    default:
        return false;
    }
}
