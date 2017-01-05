#include "StringExpr.hpp"

using namespace ast;

StringExpr::StringExpr(const std::string &str) :
    m_str(str)
{

}


bool ast::StringExpr::checkSemantic(Scope&, Report&)
{
    setType( single_town<StringType>() );
    return true;
}
