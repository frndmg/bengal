option(BENGAL_DEBUG_PARSING "Debug the parsing process" OFF)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/parsing/scanner/lex.cpp
    COMMAND flexc++ ARGS scanner/lexer.l
    MAIN_DEPENDENCY scanner/lexer.l
    DEPENDS scanner/scanner.h scanner/scanner.ih
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/parsing
    COMMENT "Generating lexer"
)

if (${BENGAL_DEBUG_PARSING})
    set(BISON_FLAGS --debug --construction)
endif()

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/parsing/parser/parse.cpp
    COMMAND bisonc++ ARGS ${BISON_FLAGS} parser/grammar.y
    MAIN_DEPENDENCY parser/grammar.y
    DEPENDS parser/parser.h parser/parser.ih parser/parserPreinclude.hpp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/parsing
    COMMENT "Generating parser"
)

set(SOURCES scanner/lex.cpp
            parser/parse.cpp)

include_directories(../ast)
include_directories(../semantic)

add_library(parsing SHARED ${SOURCES})
set_property(TARGET parsing PROPERTY CXX_STANDARD 14)
