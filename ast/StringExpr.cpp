#include "StringExpr.hpp"

using namespace ast;

StringExpr::StringExpr( const std::string& value, const Position& pos )
        : RValue( pos )
        , m_value( value )
{ }

const std::string& StringExpr::value()
{ return m_value; }

bool ast::StringExpr::checkSemantic( Scope& scope, Report& )
{
    setType( scope.getType( "string" ) );
    return true;
}

StringExpr::operator std::string() const
{ return "StringExpr( " + m_value + " )"; }
