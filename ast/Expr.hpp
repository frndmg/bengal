#ifndef EXPR_HPP
#define EXPR_HPP

#include "Node.hpp"

namespace ast
{

class Expr : public Node
{
public:
    Expr(const Position& pos = { 0, 0, 0, 0 });

    // Node interface
public:
    virtual operator std::string() const override;

    // Type property
public:
    const std::shared_ptr<Type>& type() const;
protected:
    void setType(const std::shared_ptr<Type>& type);

    ///
    /// \brief Compare with a specific type
    /// \param type
    /// \param expr_list
    /// \return
    ///
    static bool sameType(const std::shared_ptr<Type>& type,
                         const std::initializer_list<std::shared_ptr<Expr> >& expr_list);

    ///
    /// \brief Check that all have the same type
    /// \param expr_list
    /// \return
    ///
    static bool sameType(const std::initializer_list<std::shared_ptr<Expr> >& expr_list );

private:
    std::shared_ptr<Type> m_type;
};

} // namespace ast

#endif // EXPR_HPP
