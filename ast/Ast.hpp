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
    Ast(const std::shared_ptr<Expr>& root) : m_root(root) { }
    Ast(Expr* root = nullptr) : m_root( root ) { }

    bool checkSemantic();
    void generateCode();

    void setRoot(Expr* root) { m_root = std::shared_ptr<Expr>( root ); }
    void setRoot(const std::shared_ptr<Expr>& root) { m_root = root; }
    void setRoot(const std::shared_ptr<Expr>&& root) { m_root = std::move(root); }

    operator std::string() const
    {
        return "Ast( " + static_cast<std::string>( *m_root ) + " )";
    }

    friend std::ostream& operator<<(std::ostream& out, const Ast& ast)
    {
        return out << static_cast<std::string>( ast );
    }

private:
    std::shared_ptr<Expr> m_root;
};

} // ast namespace


#endif //BENGAL_AST_HPP
