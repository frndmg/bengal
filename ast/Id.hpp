#ifndef ID_HPP
#define ID_HPP

#include <string>

namespace ast
{

class Id
{
public:
    Id( const std::string& id );

private:
    std::string m_id;
};

} // ast namespace

#endif // ID_HPP
