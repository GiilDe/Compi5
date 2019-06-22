#ifndef HW3_PARSER_H
#define HW3_PARSER_H

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdarg>
#include <list>
#include "source.hpp"
#include "output.hpp"
#include "bp.hpp"
#include "parser/CodeGenerator.h"

#define tokens yytokentype
#define YYERROR_VERBOSE 1

#define code_buffer wrapper.buf()

using namespace std;
using namespace output;

/**
 * External lexical analyzer function
 */
extern int yylex();

/**
 * External parser function
 */
extern int yyparse();

extern int yydebug;

Utils utils;
Parser parser(utils);
CodeGenerator wrapper(&parser);

void yyerror(const char *err) {
    WRAP_ERROR(errorSyn(yylineno));
}

void deriveProgramAndExit() {
    parser.verifyMainFunction();
    parser.exitLastScope();
    wrapper.emitMain();
    wrapper.printBuffer();
    exit(0);
}

int main() {

//#ifdef YYDEBUG
//    yydebug = 1;
//#endif

    return yyparse();
}

#endif //HW3_PARSER_H
