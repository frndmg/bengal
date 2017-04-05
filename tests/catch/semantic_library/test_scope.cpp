#include <catch.hpp>

#include <Scope.hpp>
#include <iostream>

typedef semantic::Scope Scope;
typedef semantic::IntType IntType;
typedef semantic::StringType StringType;
typedef semantic::FunctionType FunctionType;
typedef semantic::ProcedureType ProcedureType;

TEST_CASE( "scope storing", "[scope]" )
{
    Scope scope;

    SECTION( "with types" )
    {
        auto int_type = std::make_shared<IntType>();

        scope.addType( "int", int_type );
        REQUIRE( scope["type"]["int"] == int_type );
    }

    SECTION( "with functions" )
    {
        auto function_type = std::make_shared<ProcedureType>( "test_function" );

        scope.addFunction( function_type->typeName(), function_type );
        REQUIRE( scope["function"]["test_function"] == function_type );
    }

    SECTION( "with variables" )
    {
        auto variable_type = std::make_shared<IntType>();

    }
}

TEST_CASE( "nested scopes", "[scope][nesting]" )
{
    Scope scope;

    SECTION( "int type in the parent scope" )
    {
        auto int_type = std::make_shared<IntType>();
        scope.addType( int_type->typeName(), int_type );

        Scope nested_scope( &scope );
        REQUIRE( nested_scope.getType( "int" ) == int_type );
    }

    SECTION( "nullptr if the type does not exist" )
    {
        Scope nested_scope( &scope );
        REQUIRE( nested_scope.getType( "unknown_type" ) == nullptr );
    }
}
