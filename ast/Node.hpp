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

/// \brief Base class for bengal ast nodes
class Node
{
protected:
    using Scope = semantic::Scope;
    using Report = semantic::Report;

    using Type = semantic::Type;
    using IntType = semantic::IntType;
    using StringType = semantic::StringType;
    using NilType = semantic::NilType;
    using ArrayType = semantic::ArrayType;
    using StructType = semantic::StructType;
    using FunctionType = semantic::FunctionType;
    using AliasType = semantic::AliasType;
    using Procedure = semantic::ProcedureType;
    using NoneType = semantic::NoneType;

public:
    Node( const Position& pos = { 0, 0, 0, 0 } );

    /// \brief Check the semantic of the current node.
    /// \param scope The scope of the current node.
    /// \param report The reporter to generate errors or warnings.
    /// \return true if well semantically or false otherwise.
    virtual bool checkSemantic( Scope& scope, Report& report ) = 0;

    // Commented because not implemented.
//    virtual void generateCode(const std::shared_ptr<CodeGenerator>& cg) = 0;

    /// \brief Gets the position of the node.
    /// \return The position of the node.
    const Position& position() const;

    virtual operator std::string() const;

    friend std::ostream& operator<<( std::ostream& out, const Node& n )
    { return out << static_cast<std::string>( n ); }

private:
    /// \brief Position of the node in the file.
    Position m_pos;
};

} // ast namespace

#endif // NODE_HPP
