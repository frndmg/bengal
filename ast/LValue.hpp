#ifndef LVALUE_HPP
#define LVALUE_HPP

#include "Id.hpp"
#include "RValue.hpp"


namespace ast
{

class LValue : public RValue
{
public:
    ///
    /// \brief Creates a single LValue with no member references
    /// \param id  Pointer to a Id type
    ///
    LValue(const Position& pos = { 0, 0, 0, 0 });

    ///
    /// \brief Creates a member accesor LValue
    /// \param id     Pointer to a Id type
    ///
    LValue(std::shared_ptr<Id>& id, const Position& pos = { 0, 0, 0, 0 });

    ///
    /// \brief Creates a index accesor LValue
    /// \param index  Pointer to a Expr type
    ///
    LValue(std::shared_ptr<Expr>& index, const Position& pos = { 0, 0, 0, 0 });

    void setNext(const std::shared_ptr<LValue>& next);

    bool isMemberAccesor() { return bool( m_id ); }

    bool isIndexAccesor() { return bool( m_index ); }

    bool isSimple() { return not bool( m_next ); }

    // Node interface
public:
    virtual bool checkSemantic(Scope& scope, Report& report) override;

    virtual operator std::string() const;

private:
    std::shared_ptr<Id>     m_id;
    std::shared_ptr<Expr>   m_index;
    std::shared_ptr<LValue> m_next;
};

} // ast namespace

#endif // LVALUE_HPP
