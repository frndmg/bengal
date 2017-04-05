set(TEST_SEMANTIC_LIBRARY
        run_all.cpp
        test_scope.cpp test_types.cpp)
set(TEST_SEMANTIC_LIBRARY_TARGET test_semantic_library)

include_directories(..)
include_directories(../../../semantic)
add_executable(${TEST_SEMANTIC_LIBRARY_TARGET} ${TEST_SEMANTIC_LIBRARY})
target_link_libraries(
        ${TEST_SEMANTIC_LIBRARY_TARGET}
        semantic)
