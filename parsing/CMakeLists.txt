option(BENGAL_DEBUG_PARSING "Debug the parsing process" OFF)
option(BENGAL_PARSING_PRINT_TOKENS "Print the tokens during the parsing process" OFF)

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/parsing/scanner/lex.cpp
    COMMAND flexc++ ARGS scanner/lexer.l
    MAIN_DEPENDENCY scanner/lexer.l
    DEPENDS scanner/scanner.h scanner/scanner.ih
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/parsing
    COMMENT "Generating lexer"
)

if (${BENGAL_DEBUG_PARSING})
    set(BISON_FLAGS ${BISON_FLAGS} "--debug --construction")
endif ()

if (${BENGAL_PARSING_PRINT_TOKENS})
    set(BISON_FLAGS ${BISON_FLAGS} "--print")
endif()

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/parsing/parser/parse.cpp
    COMMAND bisonc++ ARGS ${BISON_FLAGS} parser/grammar.y
    MAIN_DEPENDENCY parser/grammar.y
    DEPENDS parser/parser.h parser/parser.ih parser/parserPreinclude.hpp
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/parsing
    COMMENT "Generating parser"
)

set(BENGAL_PARSING_LIBRARY parsing)
set(SOURCES scanner/lex.cpp
            parser/parse.cpp)

include_directories(../ast)
include_directories(../semantic)

add_library(${BENGAL_PARSING_LIBRARY} SHARED ${SOURCES})
set_property(TARGET ${BENGAL_PARSING_LIBRARY} PROPERTY CXX_STANDARD 14)
