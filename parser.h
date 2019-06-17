

#ifndef HW3_PARSER_H
#define HW3_PARSER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include "source.hpp"
#include "output.hpp"
#include "parser.tab.hpp"
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
#include "bp.hpp"
#include "parser/Utils.h"
#include "parser/Parser.h"
#include "parser/MipsWrapper.h"

#define tokens yytokentype
#define YYERROR_VERBOSE 1

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

list<string> free_registers;

CodeBuffer *code_buffer;

Utils utils;
Parser parser(utils);
MipsWrapper wrapper(NULL);

void outWhile() {
    parser.outWhile();
}

void tryAddVariable(stack_data *type_class, stack_data *id_class, bool func_var) {
    if (!parser.addVariable(type_class, id_class, func_var)) {
        Id *id = dynamic_cast<Id *>(id_class);
        WRAP_ERROR(errorDef(yylineno, id->id));
    }
}

pair<int, int> getVariable(stack_data *stackData) {
    return parser.getVariable(stackData);
}

void yyerror(const char *err) {
    WRAP_ERROR(errorSyn(yylineno));
}

void concatenate_params(vector<int> &v, TypesList *t1, TypesList *t2) {
    if (t1 != NULL) {
        v.insert(v.end(), t1->params.begin(), t1->params.end());
    }
    if (t2 != NULL) {
        v.insert(v.end(), t2->params.begin(), t2->params.end());
    }
}

string get_free_register() {
    if (free_registers.empty()) {
        //do something
    }
    string free_reg = free_registers.front();
    free_registers.pop_front();
    return free_reg;
}

void free_register(string &reg) {
    free_registers.push_front(reg);
}

int string_to_int(string str) {
    stringstream s;
    int n;
    s << str;
    s >> n;
    return n;
}

void get_ID_reg(stack_data *stackData) {
    Id *id = static_cast<Id *>(stackData);
    pair<int, int> p = parser.getVariable(id);
    if (p.first != -1) {
        id->type.type = p.first;
        int offset = p.second;
        id->type.reg = utils.intToString(offset) + "($fb)";
    }
}

bool from_memory(string s) {
//    std::istringstream iss(s);
//    int num = 0;
//    bool b = (iss >> num).fail();
    return s.size() > 1 && s.at(1) != 's' && s.at(1) != 't' && !utils.isNumber(s);
}

void move_data(string dest, string src) {
    string real_src = src;
    //dest is in memory, check source
    if (from_memory(src)) {
        real_src = get_free_register();
        wrapper.lw(real_src, src);
    } else if (utils.isNumber(src)) {
        real_src = get_free_register();
        wrapper.li(real_src, src);
    }
    wrapper.sw(real_src, dest);
    if (real_src != src) {
        free_register(real_src);
    }
}

void binop(Type *dest, Type *Rsrc, Type *src, string op) {
    string sdest = dest->reg;
    string sRsrc = Rsrc->reg;
    string ssrc = src->reg;

    if (from_memory(sdest)) {
        sdest = get_free_register();
    }
    if (from_memory(sRsrc)) {
        sRsrc = get_free_register();
        wrapper.lw(sRsrc, Rsrc->reg);
    }
    if (from_memory(ssrc)) {
        ssrc = get_free_register();
        wrapper.lw(ssrc, src->reg);
    }

    if (op == "+") {
        op = "add";
    } else if (op == "-") {
        op = "sub";
    } else if (op == "*") {
        op = "mul";
    } else {
        op = "div";
    }

    string s = op + " " + sdest + ", " + sRsrc + ", " + ssrc;
    code_buffer->emit(s);
    //cout << s << endl;

    if (sdest != dest->reg) {
        wrapper.sw(sdest, dest->reg);
    }
    if (sRsrc != Rsrc->reg) {
        free_register(sRsrc);
    }
    if (ssrc != src->reg) {
        free_register(ssrc);
    }
}

string get_reg_if_mem(Type *t) {
    if (from_memory(t->reg)) {
        string reg = get_free_register();
        wrapper.lw(reg, t->reg);
        return reg;
    }
    return t->reg;
}

void bool_assignment(string dest, Type *t) {
    string T = code_buffer->genLabel();
    move_data(dest, "1");
    int skip_F_jump = code_buffer->emit("j ");
    string F = code_buffer->genLabel();
    move_data(dest, "0");
    string after_F = code_buffer->genLabel();
    code_buffer->bpatch(code_buffer->makelist(skip_F_jump), after_F);
    code_buffer->bpatch(t->true_list, T);
    code_buffer->bpatch(t->false_list, F);
}

void initialize_free_registers() {
    for (int i = 0; i <= 7; ++i) {
        string num = utils.intToString(i);
        free_registers.push_front("$t" + num);
        free_registers.push_front("$s" + num);
    }
    free_registers.push_front("$t8");
    free_registers.push_front("$t9");
}

void deriveProgramAndExit() {
    parser.verifyMainFunction();
    parser.exitLastScope();
    code_buffer->printCodeBuffer();
    exit(0);
}

int main() {
    code_buffer = &CodeBuffer::instance();
    wrapper = MipsWrapper(code_buffer);
    initialize_free_registers();

//#ifdef YYDEBUG
//    yydebug = 1;
//#endif

    return yyparse();
}

#endif //HW3_PARSER_H
