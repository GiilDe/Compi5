//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_PARSER_H
#define COMPI5_PARSER_H

#include "../output.hpp"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <stack>

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
    vector<int> param_types;
    tokens ret_type;
};

typedef map<string, var_data> ScopeTable;
typedef map<string, func_data> FuncTable;

class Parser {
private:
    Utils utils;

    vector<ScopeTable> scopes_tables;
    stack<int> offsets_stack;

    vector<string> func_names;
    FuncTable func_table;

    int in_while;
    int func_param_offset;
    int current_return_type;

    bool compare_types(const vector<int>& v1, const vector<int>& v2) const {
        if(v1.size() != v2.size()){
            return false;
        }
        for (int i = 0; i < v1.size(); ++i){
            if(!utils.isAssignable(v1[i], v2[i]))
                return false;
        }
        return true;
    }

public:

    explicit Parser(Utils& utils);

    void newScope();

    void exitScope(bool isFuncScope, stack_data* name, stack_data* precondNum);

    void exitLastScope();

    bool containsVar(const string& name) const;

    bool addVariable(stack_data *varType, stack_data *varId, bool isFunctionParameter);

    void tryAddVariable(stack_data *typeData, stack_data *idData, bool isFunctionParameter);

    pair<int, int> getVariable(stack_data* stackData);

    tokens getVariableType(const stack_data* stackData) const;

    void addFunction(vector<int> param_types, tokens ret_type, const string& name);

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
};


#endif //COMPI5_PARSER_H
