//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_PARSER_H
#define COMPI5_PARSER_H

#include "output.hpp"
#include "Utils.h"
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

using namespace std;
using namespace output;

/**
 * Line count for lex
 */
extern int yylineno;

#define tokens yytokentype

struct var_data {
    tokens type;
    int offset;
};

struct func_data {
    vector<Exp*> param_types;
    tokens ret_type;

};

class RegisterPool {
private:
    list<Register> registers;

public:
    RegisterPool() {
        Utils utils;
        for (int i = 0; i <= 7; ++i) {
            string num = utils.intToString(i);
            registers.push_front(Register("$t" + num));
            registers.push_front(Register("$s" + num));
        }
        registers.push_front(Register("$t8"));
        registers.push_front(Register("$t9"));
    }

    int size() {
        return registers.size();
    }

    Register& getFreeRegister() {
        for (list<Register>::iterator iter = registers.begin(); iter != registers.end(); ++iter) {
            if ((*iter).isFree()) {
                (*iter).acquire();
                return *iter;
            }
        }
        return registers.front();
    }

    void freeRegister(const string& name) {
        for (list<Register>::iterator iter = registers.begin(); iter != registers.end(); ++iter) {
            if ((*iter).getName() == name) {
                (*iter).release();
                return;
            }
        }
    }

    list<Register> getUsedRegisters() {
        list<Register> res;
        for (list<Register>::iterator iter = registers.begin(); iter != registers.end(); ++iter) {
            if (!(*iter).isFree()) {
                res.push_back(*iter);
            }
        }
        return res;
    }
};

class Scope {

public:
    map<string, var_data> table;
    bool isFunctionScope;
    RegisterPool regPool;
    string scopeLabel;

    Scope(const map<string, var_data> &table, bool isFunctionScope) : table(table),
                                                                      isFunctionScope(isFunctionScope),
                                                                      regPool(),
                                                                      scopeLabel("") {}

};

typedef map<string, var_data> ScopeTable;
typedef map<string, func_data> FuncTable;

class Parser {
private:
    Utils utils;

    vector<Scope> scopes_tables;
    stack<int> offsets_stack;

    vector<string> func_names;

    int in_while;
    int func_param_offset;
    int current_return_type;

    map<string, func_data> func_table;

    bool compare_types(const vector<Exp*>& v1, const vector<Exp*>& v2) const {
        if(v1.size() != v2.size()){
            return false;
        }
        for (int i = 0; i < v1.size(); ++i){
            if(!utils.isAssignable(v1[i]->type->type, v2[i]->type->type))
                return false;
        }
        return true;
    }

public:

    int scope_var_num;

    explicit Parser(Utils& utils);

    void newScope(bool isFuncScope);

    void newScope(bool isFuncScope, string label);

    void exitScope(bool isFuncScope, stack_data* name, stack_data* precondNum);

    Scope& currentScope();

    void exitLastScope();

    bool containsVar(const string& name) const;

    bool addVariable(stack_data *varType, stack_data *varId, bool isFunctionParameter);

    void tryAddVariable(stack_data *typeData, stack_data *idData, bool isFunctionParameter);

    pair<int, int> getVariable(const string& name);

    pair<int, int> getVariable(const stack_data* stackData);

    tokens getVariableType(const stack_data* stackData) const;

    void addFunction(vector<Exp*> param_types, tokens ret_type, const string& name);

    tokens getFunctionReturnType(const string& data) const;

    tokens getFunctionReturnType(stack_data* stackData) const;

    void setCurrentReturnType(stack_data* stackData);

    void verifyFunctionDefined(stack_data* stackData) const;

    void verifyRightParams(stack_data* func_name, stack_data* param_list) const;

    void verifyVariableDefined(stack_data * stackData) const;

    void verifyType(stack_data *stackData, int t) const;

    void verifyByteSize(stack_data* stackData) const;

    void verifyIdType(stack_data* idStackData, stack_data* expStackData) const;

    void verifyReturn(int type) const;

    int verifyTypes(stack_data *stackData, int num, ...) const;

    void verifyBreak() const;

    void verifyContinue() const;

    void verifyMainFunction() const;

    void addFunctionDeclaration(stack_data* retType, stack_data *idVarData, stack_data* typesList);

    void inWhile();

    void outWhile();
//
//    Register getFreeRegister();
//
//    void freeRegister(const string& name);
//
//    list<Register> getUsedRegisters();
};


#endif //COMPI5_PARSER_H
