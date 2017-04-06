#include <catch.hpp>

#include <parser.h>

TEST_CASE( "lvalue expression", "[lvalue]" )
{
    SECTION( "simple" )
    {
        std::fstream fstream( "lvalue_expr/simple01.tig" );
        REQUIRE( fstream );

        Parser parser( fstream );
        REQUIRE( parser.parse() == 0 );

        Ast& ast = parser.ast();
        REQUIRE( ast.checkSemantic() );
    }
}

TEST_CASE( "invalid lvalue expression", "[lvalue][fail]")
{
    SECTION( "invalid member accessor" )
    {
        std::fstream fstream( "lvalue_expr/invalid_member_accessor.tig" );
        REQUIRE(fstream);

        Parser parser( fstream );
        REQUIRE( parser.parse() == 0 );

        Ast& ast = parser.ast();
        REQUIRE( not ast.checkSemantic() );
    }

    SECTION( "invalid index accessor" )
    {
        std::fstream fstream( "lvalue_expr/invalid_index_accessor.tig" );
        REQUIRE(fstream);

        Parser parser( fstream );
        REQUIRE( parser.parse() == 0 );

        Ast& ast = parser.ast();
        REQUIRE( not ast.checkSemantic() );
    }
}
