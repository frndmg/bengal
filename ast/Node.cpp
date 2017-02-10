#include "Node.hpp"


using namespace ast;

size_t Node::column() const
{
    return m_column;
}

void Node::setColumn(const size_t& column)
{
    m_column = column;
}

void Node::setPos(const size_t& line, const size_t& column)
{
    m_line = line; m_column = column;
}

size_t Node::line() const
{
    return m_line;
}

void Node::setLine(const size_t& line)
{
    m_line = line;
}
