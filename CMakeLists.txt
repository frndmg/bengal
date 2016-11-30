cmake_minimum_required(VERSION 3.0)

project(bengal CXX)

# TODO: Tell Danilo to fix this
#include(cmake/FindFLEXCPP.cmake)
#include(cmake/FindBISONCPP.cmake)

set(BOOST_COMPONENTS program_options filesystem)
find_package(Boost 1.54 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

include_directories(ast parsing/parser)

add_subdirectory(ast)
add_subdirectory(parsing)

set(TARGET tiger)
add_executable(${TARGET} main.cpp)
set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 11)
target_link_libraries(${TARGET} ast parsing ${Boost_LIBRARIES})
