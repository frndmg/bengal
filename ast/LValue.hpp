#ifndef LVALUE_HPP
#define LVALUE_HPP

#define LVALUE_INVALID_MEMBER_ACCESSOR "Invalid use of member accessor in a type that is not a struct"

#define LVALUE_MISSING_MEMBER "Struct %s does not have a member named %s"

#define LVALUE_INVALID_INDEX_ACCESSOR "Invalid index accessor over a no array type"

#define LVALUE_INDEX_NOT_A_NUMBER "Index is not a number"

#include "Id.hpp"
#include "RValue.hpp"


namespace ast
{

class LValue
        : public RValue
{
public:
    /// \brief Creates an empty LValue.
    LValue( const Position& pos = { 0, 0, 0, 0 } );

    /// \brief Creates a member accessor.
    /// \param id Pointer to Id type.
    LValue(
            const std::shared_ptr<Id>& id,
            const Position& pos = { 0, 0, 0, 0 } );

    /// \brief Creates an index accessor.
    /// \param index Pointer to a Expr type.
    LValue(
            const std::shared_ptr<Expr>& index,
            const Position& pos = { 0, 0, 0, 0 } );

    void setNext( const std::shared_ptr<LValue>& next );

    /// \brief Gets if the current LValue is a member accessor.
    /// \return true if the current LValue is a member accessor,
    ///         false otherwise.
    bool isMemberAccessor();

    /// \brief Gets if the current LValue is index accessor.
    /// \return true if the current LValue is a member accessor,
    ///         false otherwise.
    bool isIndexAccessor();

    /// \brief Gets if the current LValue is empty.
    /// \details If it is not a member accessor neither an index accessor.
    /// \return true if the current LValue is a member accessor,
    ///         false otherwise.
    bool isEmpty();

    const std::shared_ptr<Id>& id() const;

    const std::shared_ptr<Expr>& index() const;

    const std::shared_ptr<LValue>& next() const;

public:
    virtual bool checkSemantic( Scope& scope, Report& report ) override;

private:
    bool checkSemantic(
            std::shared_ptr<Type>& parent_type,
            Scope& scope,
            Node::Report& report );

public:

    virtual operator std::string() const;

private:
    std::shared_ptr<Id> m_id;
    std::shared_ptr<Expr> m_index;
    std::shared_ptr<LValue> m_next;
};

} // ast namespace

#endif // LVALUE_HPP
