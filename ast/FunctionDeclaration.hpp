#ifndef FUNCTIONDECLARATION_HPP
#define FUNCTIONDECLARATION_HPP

#include "Expr.hpp"
#include "Node.hpp"
#include "TypeFields.hpp"

namespace ast
{

class FunctionDeclaration : public Node
{
public:
    FunctionDeclaration(ptr<Id> id, ptr<TypeFields> arguments, ptr<Expr> body, ptr<Id> retType = nullptr);

private:
    ptr<Id> m_id;
    ptr<TypeFields> m_arguments;
    ptr<Expr> m_body;
    ptr<Id> m_retType;
};

} // ast namespace

#endif // FUNCTIONDECLARATION_HPP
