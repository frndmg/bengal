#define BOOST_TEST_MODULE Binary Expresion

#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

namespace but = boost::unit_test;
namespace bdata = boost::unit_test::data;

#include <BinExpr.hpp>
#include <NumExpr.hpp>
#include <Ast.hpp>

// Binary Expression Suite
BOOST_TEST_DECORATOR(* but::label("binary-expression"))
BOOST_AUTO_TEST_SUITE(binary_expression)

BOOST_TEST_DECORATOR( * but::label("simple")
                      * but::description("Basic use of binary expression") )
BOOST_AUTO_TEST_CASE(with_num)
{
    // 5 + 10
    auto n = std::make_shared<ast::NumExpr>(5);
    auto m = std::make_shared<ast::NumExpr>(10);
    auto b = std::make_shared<ast::BinExpr>(n, m, ast::BinExpr::ADD);
    ast::Ast AST( b );

    std::cout << AST << ";" << std::endl;

    BOOST_TEST( AST.checkSemantic() );
}

BOOST_AUTO_TEST_SUITE_END()
// Binary Expression Suite End
