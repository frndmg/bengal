set(SOURCES scanner/lex.cpp
            parser/parse.cpp)

include_directories(../ast)

add_library(parsing SHARED ${SOURCES})
set_property(TARGET parsing PROPERTY CXX_STANDARD 11)
