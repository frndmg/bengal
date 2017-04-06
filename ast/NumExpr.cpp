#include "NumExpr.hpp"

using namespace ast;

NumExpr::NumExpr( int value, const Position& pos )
        : RValue( pos )
        , m_value( value )
{ }

int NumExpr::value() const
{ return m_value; }

bool NumExpr::checkSemantic( Scope& scope, Report& )
{
    setType( scope.getType( "int" ) );
    return true;
}

NumExpr::operator std::string() const
{
    return "NumExpr( " + std::to_string( m_value ) + " )";
}
