set(TEST_LVALUE_EXPR_SOURCE_FILES
        run_all.cpp
        test_lvalue_expr.cpp
        )
set(TEST_LVALUE_EXPR_TARGET test_lvalue_expr)

include_directories(..)
add_executable(${TEST_LVALUE_EXPR_TARGET} ${TEST_LVALUE_EXPR_SOURCE_FILES})
target_link_libraries(
        ${TEST_LVALUE_EXPR_TARGET}
        ast parsing semantic)
