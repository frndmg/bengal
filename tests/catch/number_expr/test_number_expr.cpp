#include <catch.hpp>

#include <parser.h>

TEST_CASE( "positive numbers", "[positive]" )
{
    std::fstream fstream( "int_expr/positive.tig" );

    REQUIRE( fstream );

    Parser parser( fstream );

    REQUIRE( parser.parse() == 0 );
}

TEST_CASE( "negative numbers", "[negative]" )
{
    std::fstream fstream( "int_expr/negative.tig" );

    REQUIRE( fstream );

    Parser parser( fstream );

    REQUIRE( parser.parse() == 0 );
}
