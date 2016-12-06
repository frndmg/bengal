#include "FunctionDeclaration.hpp"

using namespace ast;

FunctionDeclaration::FunctionDeclaration(ptr<Id> id, ptr<TypeFields> arguments, ptr<Expr> body, ptr<Id> retType) :
    m_id(id),
    m_arguments(arguments),
    m_body(body),
    m_retType(retType)
{

}
