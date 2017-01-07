#ifndef ID_HPP
#define ID_HPP

#include <string>

namespace ast
{

class Id : public std::string
{
public:
    Id(const std::string& s) : std::string( s ) {}
};

} // ast namespace

#endif // ID_HPP
