cmake_minimum_required(VERSION 3.0)

project(bengal CXX)

include(CMakeToolsHelpers OPTIONAL)

# TODO: Tell Danilo to fix this
#include(cmake/FindFLEXCPP.cmake)
#include(cmake/FindBISONCPP.cmake)

set(BOOST_COMPONENTS program_options)
find_package(Boost 1.54 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

include_directories(ast parsing/parser semantic)

add_subdirectory(ast)
add_subdirectory(parsing)
add_subdirectory(semantic)

enable_testing()
add_subdirectory(tests)

set(TARGET tiger)
add_executable(${TARGET} main.cpp)
set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 14)
target_link_libraries(${TARGET} ast parsing semantic ${Boost_LIBRARIES})
