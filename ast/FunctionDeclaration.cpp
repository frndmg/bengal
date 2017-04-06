#include <set>
#include "FunctionDeclaration.hpp"

using namespace ast;

FunctionDeclaration::FunctionDeclaration(
        const std::shared_ptr<Id>& id,
        const std::shared_ptr<TypeFields>& arguments,
        const std::shared_ptr<Expr>& body,
        const std::shared_ptr<Id>& retType )
        : m_id( id )
        , m_arguments( arguments )
        , m_body( body )
        , m_retType( retType )
{ }

bool FunctionDeclaration::checkSemantic( Scope& scope, Report& report )
{
    // All in a function declaration occurs inside a new scope.
    Scope nested_scope( &scope );

    bool ok = checkArguments( nested_scope, report );

    std::string return_type_name;
    if ( returnType() != nullptr )
    {
        return_type_name = *returnType();
    }
    if ( return_type_name == "none" )
    {
        // This name can not be used be the user.
        report.error( *this,
                      "Invalid use of type none, write nothing instead." );
        ok = false;
        // Continue getting the errors.
    }
    else if ( return_type_name == "" )
    {
        // If there is no type the function is a procedure.
        return_type_name = "none";
    }

    auto return_type = nested_scope.getType( return_type_name );

    // Check the body of the function.
    ok = body()->checkSemantic( nested_scope, report ) and ok;

    if ( return_type_name != "none" and return_type != body()->type() )
    {
        report.error( *this,
                      "The return type %s does not match",
                      return_type->typeName().c_str() );
        ok = false;
    }

    return ok;
}

bool FunctionDeclaration::checkArguments( Scope& scope, Report& report ) const
{
    bool ok = true;
    for ( auto& x : *arguments() )
    {
        auto variable_type = scope.getType( *x->type() );

        if ( variable_type == nullptr )
        {
            // If the variable has an invalid type.
            report.error( *x,
                          "The type %s does not exist in the current scope.",
                          x->type()->c_str() );
            ok = false;

            continue;
        }

        if ( not scope.addVariable( *x->id(), variable_type ) )
        {
            // If the variable already defined.
            report.error( *x, "The variable name %s already taken.",
                          x->id()->c_str() );
            ok = false;
        }
    }
    return ok;
}
