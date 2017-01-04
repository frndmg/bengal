#include "Node.hpp"

#include <exception>

using namespace ast;

const std::shared_ptr<Type>& Node::type() const
{
    return m_type;
}

void Node::setType(const std::shared_ptr<Node::Type>& type)
{
    m_type = type;
}

Node::~Node()
{
}
