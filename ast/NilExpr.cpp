#include "NilExpr.hpp"

using namespace ast;

NilExpr::NilExpr( const Position& pos )
        : RValue( pos )
{ }

bool NilExpr::checkSemantic( Scope& scope, Report& report )
{
    setType( scope.getType( "nil" ) );
    return true;
}

ast::NilExpr::operator std::string() const
{
    return "Nil()";
}
