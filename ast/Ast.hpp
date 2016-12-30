//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_AST_HPP
#define BENGAL_AST_HPP

#include "utils.hpp"
#include "Expr.hpp"

namespace ast
{

class Ast
{
public:
    bool checkSemantics();
    void generateCode();

    void setRoot(const ptr<Expr>& root) { m_root = root; }
    void setRoot(const ptr<Expr>&& root) { m_root = root; }

private:
    ptr<Expr> m_root;
};

} // ast namespace


#endif //BENGAL_AST_HPP
