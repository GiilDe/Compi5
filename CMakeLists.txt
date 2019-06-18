cmake_minimum_required(VERSION 3.14)
project(Compi5)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

FIND_PACKAGE(BISON)
FIND_PACKAGE(FLEX)

BISON_TARGET(
        Parser # Just a name
        ${CMAKE_CURRENT_SOURCE_DIR}/parser.ypp ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp # path to save output
        COMPILE_FLAGS "-v"
)

FLEX_TARGET(
        Lexer
        ${CMAKE_CURRENT_SOURCE_DIR}/scanner.lex ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp
)

ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(hw5 ${BISON_Parser_OUTPUTS} ${FLEX_Lexer_OUTPUTS}
        bp.cpp source.hpp parser.h lexer.cpp output.cpp parser/Utils.cpp parser/Utils.h parser/Parser.cpp parser/Parser.h parser/CodeGenerator.cpp parser/CodeGenerator.h)