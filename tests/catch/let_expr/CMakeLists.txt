set(TEST_LET_EXPR_SOURCE_FILES
        run_all.cpp
        type_declaration.cpp
        function_declaration.cpp
        )
set(TEST_LET_EXPR_TARGET test_let_expr)

include_directories(..)
add_executable(${TEST_LET_EXPR_TARGET} ${TEST_LET_EXPR_SOURCE_FILES})
target_link_libraries(
        ${TEST_LET_EXPR_TARGET}
        ast parsing semantic)
