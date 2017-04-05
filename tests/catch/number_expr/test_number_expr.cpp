#include <catch.hpp>

#include <parser.h>

TEST_CASE( "Positive Numbers", "[positive]" )
{
    std::fstream fstream( "int_expr/positive.tig" );

    REQUIRE( fstream );

    Parser parser( fstream );

    REQUIRE( parser.parse() == 0 );
}

TEST_CASE( "Negative Numbers", "[negative]" )
{
    std::fstream fstream( "int_expr/negative.tig" );

    REQUIRE( fstream );

    Parser parser( fstream );

    REQUIRE( parser.parse() == 0 );
}
