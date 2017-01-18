//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_AST_HPP
#define BENGAL_AST_HPP

#include "Expr.hpp"

#include <memory>

namespace ast
{

class Ast
{
public:
    bool checkSemantic();
    void generateCode();

    void setRoot(const std::shared_ptr<Expr>& root) { m_root = root; }
    void setRoot(const std::shared_ptr<Expr>&& root) { m_root = std::move(root); }

private:
    ptr<Expr> m_root;
};

} // ast namespace


#endif //BENGAL_AST_HPP
