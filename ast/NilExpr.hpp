#ifndef NILEXPR_HPP
#define NILEXPR_HPP

#include "RValue.hpp"

namespace ast
{

class NilExpr
        : public RValue
{
public:
    NilExpr( const Position& pos = { 0, 0, 0, 0 } );

    // Node interface
public:
    virtual bool checkSemantic( Scope&, Report& ) override;

    virtual operator std::string() const override;
};

} // ast namespace

#endif // NILEXPR_HPP
