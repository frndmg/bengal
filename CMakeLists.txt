project(bengal CXX)
cmake_minimum_required(VERSION 2.8)

# TODO: Tell Danilo to fix this
#include(cmake/FindFLEXCPP.cmake)
#include(cmake/FindBISONCPP.cmake)

set(TARGET tiger)

add_subdirectory(ast)

add_executable(${TARGET} main.cpp scanner/lex.cpp parser/parse.cpp)
set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 11)

target_link_libraries(${TARGET} ast)
