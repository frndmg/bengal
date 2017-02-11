#include "NumExpr.hpp"

using namespace ast;

NumExpr::NumExpr(int val, const Position& pos) :
    RValue( pos ),
    m_val( val )
{
}

bool NumExpr::checkSemantic(Scope&, Report&)
{
    setType( single_town<IntType>() );
    return true;
}

NumExpr::operator std::string() const
{
    return "NumExpr( " + std::to_string(m_val) + " )";
}
