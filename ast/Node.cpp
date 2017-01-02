#include "Node.hpp"

#include <exception>

using namespace ast;

std::shared_ptr<Node::Type> Node::type() const
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
