project(bengal CXX)
cmake_minimum_required(VERSION 2.8)

add_executable(tiger main.cpp scanner/lex.cpp parser/parse.cpp)
