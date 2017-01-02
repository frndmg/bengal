#ifndef ID_HPP
#define ID_HPP

#include <string>

namespace ast
{

class Id
{
public:
    Id( const std::string& id );

    std::string id() const;

private:
    std::string m_id;
};

} // ast namespace

#endif // ID_HPP
