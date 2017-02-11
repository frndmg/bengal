#ifndef NODE_HPP
#define NODE_HPP

#include "../utils.hpp"
//#include "CodeGenerator.hpp"

// Semantic
#include <Scope.hpp>
#include <Report.hpp>

#include <iostream>

namespace ast
{

class Node
{
protected:
    using Scope = semantic::Scope;
    using Report = semantic::Report;

public:
    Node(const Position& pos = { 0, 0, 0, 0 });
    virtual ~Node() { }

// Virtual Methods
//    virtual void generateCode(const std::shared_ptr<CodeGenerator>& cg) = 0;

    ///
    /// \brief checkSemantic
    /// \param scope
    /// \param report
    /// \return
    ///
    virtual bool checkSemantic(Scope& scope, Report& report) = 0;
    virtual operator std::string() const;

    friend std::ostream& operator<<(std::ostream& out, const Node& n)
    {
        return out << static_cast<std::string>( n );
    }

    const Position& position() const;

private:
    Position m_pos;
};

} // ast namespace

#endif // NODE_HPP
