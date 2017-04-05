
set(TEST_NUMBER_EXPR_SOURCE_FILES
        run_all.cpp
        test_number_expr.cpp
        )
set(TEST_NUMBER_EXPR_TARGET test_number_expr)

include_directories(..)
add_executable(${TEST_NUMBER_EXPR_TARGET} ${TEST_NUMBER_EXPR_SOURCE_FILES})
target_link_libraries(
        ${TEST_NUMBER_EXPR_TARGET}
        ast parsing semantic)
