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
    FunctionDeclaration(std::shared_ptr<Id> id, std::shared_ptr<TypeFields> arguments, std::shared_ptr<Expr> body, std::shared_ptr<Id> retType = nullptr);

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<TypeFields> m_arguments;
    std::shared_ptr<Expr> m_body;
    std::shared_ptr<Id> m_retType;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace

#endif // FUNCTIONDECLARATION_HPP
