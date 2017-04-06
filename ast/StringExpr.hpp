#ifndef STRINGEXPR_HPP
#define STRINGEXPR_HPP

#include "RValue.hpp"

#include <string>

namespace ast
{

class StringExpr
        : public RValue
{
public:
    StringExpr(
            const std::string& value,
            const Position& pos = { 0, 0, 0, 0 } );

    const std::string& value();

    virtual bool checkSemantic( Scope& scope, Report& report ) override;

    virtual operator std::string() const override;

private:
    std::string m_value;
};

} // ast namespace


#endif // STRINGEXPR_HPP
