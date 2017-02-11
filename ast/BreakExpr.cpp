//
// Created by frnd on 12/30/16.
//

#include "BreakExpr.hpp"

using namespace ast;

BreakExpr::BreakExpr(const Position& pos) : Expr( pos ) { }

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

ast::BreakExpr::operator std::string() const
{
    return "BreakExpr()";
}
