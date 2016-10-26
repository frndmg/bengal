project(bengal CXX)
cmake_minimum_required(VERSION 2.8)

# TODO: Tell Danilo to fix this
#include(cmake/FindFLEXCPP.cmake)
#include(cmake/FindBISONCPP.cmake)

add_subdirectory(ast)

add_executable(tiger main.cpp scanner/lex.cpp parser/parse.cpp)
set_property(TARGET tiger PROPERTY CXX_STANDARD 14)
