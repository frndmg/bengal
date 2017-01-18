#ifndef NODE_HPP
#define NODE_HPP

#include "../utils.hpp"
//#include "CodeGenerator.hpp"

// Semantic
#include <Scope.hpp>
#include <Report.hpp>

namespace ast
{

class Node
{
    size_t m_line;
    size_t m_column;

protected:
    using Scope = semantic::Scope;
    using Report = semantic::Report;

public:
    virtual ~Node() { }

//    virtual void generateCode(const std::shared_ptr<CodeGenerator>& cg) = 0;
    virtual bool checkSemantic(Scope& scope, Report& report) = 0;

    size_t line() const;
    void setLine(const size_t& line);
    size_t column() const;
    void setColumn(const size_t& column);

    void setPos(const size_t& line, const size_t& column);
};

} // ast namespace

#endif // NODE_HPP
