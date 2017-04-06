#ifndef BENGAL_AST_HPP
#define BENGAL_AST_HPP

#include "Expr.hpp"

namespace ast
{

class Ast
{
public:
    /// \brief Creates a new instance with a root.
    /// \param root The root of the ast.
    Ast( const std::shared_ptr<Expr>& root = nullptr )
            : m_root( root )
    { }

    /// \brief Check the semantic of the ast.
    /// \return true if the ast is well semantically or false otherwise.
    bool checkSemantic();

    /// \brief Generate the code of the ast.
    void generateCode();

    /// \brief Gets the root of the ast.
    /// \return The root of the ast.
    const std::shared_ptr< Expr >& root()
    { return m_root; }

    /// \brief Set the root of the ast.
    /// \param root The new root of the ast.
    void setRoot( const std::shared_ptr<Expr>& root )
    { m_root = root; }

    void setRoot( const std::shared_ptr<Expr>&& root )
    { m_root = std::move( root ); }

    operator std::string() const;

    friend std::ostream& operator<<( std::ostream& out, const Ast& ast )
    { return out << static_cast<std::string>( ast ); }

private:
    /// \brief Root of the ast.
    std::shared_ptr<Expr> m_root;
};

} // ast namespace

#endif // BENGAL_AST_HPP
