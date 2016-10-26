#ifndef NODE_HPP
#define NODE_HPP

namespace ast
{

class Node
{
public:
    Node();
    virtual ~Node();

    virtual void generateCode() = 0;
};

} // ast namespace

#endif // NODE_HPP
