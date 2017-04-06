#ifndef NUMEXPR_HPP
#define NUMEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class NumExpr
        : public RValue
{
public:
    /// \brief Creates a NumExpr with value val in position pos.
    /// \param value Value.
    /// \param pos Position in file.
    NumExpr( int value, const Position& pos = { 0, 0, 0, 0 } );

    /// \brief Gets the value of the current NumExpr.
    /// \return The value of the current NumExpr.
    int value() const;

    virtual bool checkSemantic( Scope&, Report& ) override;

//    virtual void generateCode();

    virtual operator std::string() const override;

private:
    int m_value;
};

} // ast namespace

#endif // NUMEXPR_HPP
