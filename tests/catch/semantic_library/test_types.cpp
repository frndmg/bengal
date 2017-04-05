#include <catch.hpp>

#include <Types.hpp>

typedef semantic::IntType IntType;
typedef semantic::StringType StringType;
typedef semantic::NilType NilType;
typedef semantic::NoneType NoneType;

TEST_CASE( "single town types", "[types][single-town]" )
{
    SECTION( "int type" )
    {
        // The same instance
        REQUIRE( std::make_shared<IntType>() == std::make_shared<IntType>() );
    }

    SECTION( "string type" )
    {
        REQUIRE( std::make_shared<StringType>() == std::make_shared<StringType>() );
    }

    SECTION( "nil type" )
    {
        REQUIRE( std::make_shared<NilType>() == std::make_shared<NilType>() );
    }

    SECTION( "none type" )
    {
        REQUIRE( std::make_shared<NoneType>() == std::make_shared<NoneType>() );
    }
}
