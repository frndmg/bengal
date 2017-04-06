//
// Created by frnd on 12/30/16.
//

#include "BreakExpr.hpp"

using namespace ast;

BreakExpr::BreakExpr(const Position& pos) : Expr( pos ) { }

bool BreakExpr::checkSemantic(Scope &scope, Report &report)
{
    switch ( scope.scopeType() )
    {
    case Scope::BreakableScope:
        // You can not assign to something that can be breakable
        setType( scope.getType( "none" ) );
        return true;
    default:
        report.error( *this, "Not breakable scope" );
        return false;
    }
}

ast::BreakExpr::operator std::string() const
{
    return "BreakExpr()";
}
