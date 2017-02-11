#ifndef STRINGEXPR_HPP
#define STRINGEXPR_HPP

#include "RValue.hpp"

#include <string>

namespace ast
{

class StringExpr : public RValue
{
public:
    StringExpr(const std::string& str,
               const Position& pos = { 0, 0, 0, 0 });

private:
    std::string m_str;

    // Node interface
public:
    virtual bool checkSemantic(Scope &scope, Report &report) override;
};

} // ast namespace


#endif // STRINGEXPR_HPP
