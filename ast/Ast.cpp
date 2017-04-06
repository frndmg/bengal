#include "Ast.hpp"

using namespace ast;

bool Ast::checkSemantic()
{
    typedef semantic::Scope Scope;
    typedef semantic::Report Report;
    typedef semantic::IntType IntType;
    typedef semantic::StringType StringType;
    typedef semantic::NilType NilType;
    typedef semantic::NoneType NoneType;
    typedef semantic::FunctionType FunctionType;
    typedef semantic::ProcedureType ProcedureType;

    Scope scope;
    Report report;

    // Basic types
    auto int_type = std::make_shared<IntType>();
    auto string_type = std::make_shared<StringType>();

    // Insert in the most higher scope the basic types and the standard library.
    scope.addType( int_type->typeName(), int_type );
    scope.addType( string_type->typeName(), string_type );

    // TODO: Insert the standard library.

    return m_root->checkSemantic( scope, report );
}

void Ast::generateCode()
{ }

Ast::operator std::string() const
{ return "Ast( " + static_cast<std::string>( *m_root ) + " )"; }
