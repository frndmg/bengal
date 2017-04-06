#include <catch.hpp>

#include <parser.h>

TEST_CASE( "type declaration can be an alias", "[type-declaration][alias]" )
{
    SECTION( "alias of length one" )
    {
        std::fstream fstream( "let_expr/type_declaration/alias.tig" );
        REQUIRE( fstream );  // The file exist

        Parser parser( fstream );
        REQUIRE( parser.parse() == 0 );  // It is well parsed

        Ast& ast = parser.ast();
        REQUIRE( ast.checkSemantic() );  // It is well semantically
    }
}

TEST_CASE( "type declaration can be an array", "[type-declaration][array]" )
{
    SECTION( "array of int" )
    {
        std::fstream fstream( "let_expr/type_declaration/array_of_int.tig" );
        REQUIRE( fstream );

        Parser parser( fstream );
        REQUIRE( parser.parse() == 0 );

        Ast& ast = parser.ast();
        REQUIRE( ast.checkSemantic() );
    }
}

TEST_CASE( "type declaration can be a struct", "[type-declaration][struct]" )
{
    SECTION( "struct of two fields" )
    {
        std::fstream fstream( "let_expr/type_declaration/two_fields.tig" );
        REQUIRE( fstream );

        Parser parser( fstream );
        REQUIRE( parser.parse() == 0 );

        Ast& ast = parser.ast();
        REQUIRE( ast.checkSemantic() );
    }
}
