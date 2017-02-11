#include "StringExpr.hpp"

using namespace ast;

StringExpr::StringExpr(const std::string &str, const Position& pos) :
    RValue( pos ),
    m_str(str)
{
}


bool ast::StringExpr::checkSemantic(Scope& scope, Report&)
{
    setType( scope.getTypeDef( "string" ) );
    return true;
}
