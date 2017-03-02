#include "Node.hpp"


using namespace ast;

Node::operator std::string() const
{
    return "Node()";
}

Node::Node(const Position& pos) : m_pos( pos ) { }

const Position& Node::position() const
{
    return m_pos;
}
