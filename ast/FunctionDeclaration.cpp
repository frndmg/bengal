#include "FunctionDeclaration.hpp"

using namespace ast;

FunctionDeclaration::FunctionDeclaration(std::shared_ptr<Id> id, std::shared_ptr<TypeFields> arguments, std::shared_ptr<Expr> body, std::shared_ptr<Id> retType) :
    m_id(id),
    m_arguments(arguments),
    m_body(body),
    m_retType(retType)
{

}


bool ast::FunctionDeclaration::checkSemantic(Scope &scope, Report &report)
{
}