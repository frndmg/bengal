#ifndef STRINGEXPR_HPP
#define STRINGEXPR_HPP

#include "RValue.hpp"

#include <string>

namespace ast
{

class StringExpr : public RValue
{
public:
    StringExpr(const std::string& str);

private:
    std::string m_str;
};

} // ast namespace


#endif // STRINGEXPR_HPP
