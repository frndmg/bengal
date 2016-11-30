option(BENGAL_DEBUG_PARSING "Debug the parsing process" OFF)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/parsing/scanner/lex.cpp
    COMMAND flexc++ ARGS scanner/lexer
    MAIN_DEPENDENCY scanner/lexer
    DEPENDS scanner/scanner.h scanner/scanner.ih
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/parsing
    COMMENT "Generating lexer"
)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/parsing/parser/parse.cpp
    COMMAND bisonc++ ARGS $<$<STREQUAL:BENGAL_DEBUG_PARSING,ON>:"--debug --construction"> parser/grammar
    MAIN_DEPENDENCY parser/grammar
    DEPENDS parser/parser.h parser/parser.ih parser/parserPreinclude.hpp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/parsing
    COMMENT "Generating parser"
)

set(SOURCES scanner/lex.cpp
            parser/parse.cpp)

include_directories(../ast)

add_library(parsing SHARED ${SOURCES})
set_property(TARGET parsing PROPERTY CXX_STANDARD 11)
