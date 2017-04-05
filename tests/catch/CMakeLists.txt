
set(TEST_SOURCE_FILES run_all.cpp
        number_expr/test_number_expr.cpp
        let_expr/type_declaration.cpp
        let_expr/function_declaration.cpp
        semantic_library/test_scope.cpp
        semantic_library/test_types.cpp)
set(TEST_TARGET test_all)

include_directories(.)

add_executable(${TEST_TARGET} ${TEST_SOURCE_FILES})
target_link_libraries(${TEST_TARGET} ast parsing semantic)

add_subdirectory(number_expr)
add_subdirectory(let_expr)
add_subdirectory(semantic_library)
