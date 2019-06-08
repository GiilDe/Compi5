

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


#define tokens yytokentype
#define YYERROR_VERBOSE 1

#define FOR_EACH(iter, ds, name) \
    for (ds::iterator iter = name.begin(); iter != name.end(); iter++)

#define FOR_EACH_CONST(iter, ds, name) \
    for (__wrap_iter<ds::const_pointer> iter = name.begin(); iter != name.end(); iter++)


#define WRAP_ERROR(exp) \
    do { \
        exp; \
        exit(1); \
    } while (0)

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

/**
 * Line count for lex
 */
extern int yylineno;
extern int yydebug;

int in_while = 0;
int func_param_offset;
int current_return_type;

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

vector<string> func_names;
vector<ScopeTable> scopes_tables;
stack<int> offsets_stack;
FuncTable func_table;

list<string> free_registers;

map<int, string> type_to_string;

CodeBuffer* code_buffer;


void initizlize_type_to_string(){
    type_to_string.insert(pair<int, string>(VOID, "VOID"));
    type_to_string.insert(pair<int, string>(INT, "INT"));
    type_to_string.insert(pair<int, string>(BOOL, "BOOL"));
    type_to_string.insert(pair<int, string>(BYTE, "BYTE"));
    type_to_string.insert(pair<int, string>(STRING, "STRING"));
}

set<int> int_convertables;

bool compare_types(int assignee, int rvalue) {
    if(assignee == rvalue || (assignee == INT && (int_convertables.find(rvalue) != int_convertables.end()))) {
        return true;
    }
    return false;
}

bool compare_types(vector<int>& v1, vector<int>& v2){
    if(v1.size() != v2.size()){
        return false;
    }
    for (int i = 0; i < v1.size(); ++i){
        if(!compare_types(v1[i], v2[i]))
            return false;
    }
    return true;
}

bool var_comp(const pair<string, var_data>& v1, const pair<string, var_data>& v2) {
    var_data d1 = v1.second;
    var_data d2 = v2.second;
    return d1.offset < d2.offset;
}

bool var_comp_rev(const pair<string, var_data>& v1, const pair<string, var_data>& v2) {
    var_data d1 = v1.second;
    var_data d2 = v2.second;
    return d1.offset > d2.offset;
}

void exit_scope(bool is_func, stack_data* name, stack_data* precond_num) {
    endScope();
    if(is_func){
        string id = dynamic_cast<Id*>(name)->id;
        int n = dynamic_cast<Preconditions*>(precond_num)->preconditions_num;
        printPreconditions(id, n);
    }
    int offset = offsets_stack.top();
    offsets_stack.pop();
    ScopeTable& vars_to_print = scopes_tables.back();
    vector<pair<string, var_data> > vars_pos;
    vector<pair<string, var_data> > vars_neg;

    for (map<string, var_data>::iterator i = vars_to_print.begin(); i != vars_to_print.end(); ++i) {
        pair<string, var_data> d = *i;
        var_data data = d.second;
        if(data.offset >= 0)
            vars_pos.push_back(d);
        else
            vars_neg.push_back(d);
    }

    sort(vars_pos.begin(), vars_pos.end(), var_comp);
    sort(vars_neg.begin(), vars_neg.end(), var_comp_rev);

    for(vector<pair<string, var_data> >::iterator j = vars_neg.begin(); j != vars_neg.end(); ++j){
        pair<string, var_data> i = *j;
        printID(i.first, i.second.offset, type_to_string[i.second.type]);
    }

    for(vector<pair<string, var_data> >::iterator j = vars_pos.begin(); j != vars_pos.end(); ++j){
        pair<string, var_data> i = *j;
        printID(i.first, i.second.offset, type_to_string[i.second.type]);
    }

    scopes_tables.pop_back();
}

void new_scope() {
    func_param_offset = -1;
    offsets_stack.push(offsets_stack.top());
    scopes_tables.push_back(ScopeTable());
}

bool contains_var(string &name) {
    for (vector<ScopeTable>::iterator i = scopes_tables.begin(); i != scopes_tables.end(); ++i) {
        ScopeTable &t = *i;
        if (t.find(name) != t.end()) {
            return true;
        }
    }
    return false;
}

void exit_last_scope(){
    endScope();
    for(int i = 0; i < func_names.size(); i++){
        string& name = func_names[i];
        func_data data = func_table[name];
        string ret_type = type_to_string[data.ret_type];
        vector<string> args;
        for(vector<int>::iterator i = data.param_types.begin(); i != data.param_types.end(); ++i){
            int type = *i;
            args.push_back(type_to_string[type]);
        }
        string s = makeFunctionType(ret_type, args);
        string to_print = name + " " + s + " " + "0";
        cout << to_print << endl;
    }
}

bool addVariable(stack_data *varType, stack_data *varId, bool isFunctionParameter) {
    Type *conv1 = dynamic_cast<Type *>(varType);
    Id *conv2 = dynamic_cast<Id *>(varId);

    tokens type = static_cast<tokens>(conv1->type);
    string name = conv2->id;

    if (contains_var(name) || func_table.find(name) != func_table.end()) {
        return false;
    }
    int *offset;
    if (isFunctionParameter)
        offset = &func_param_offset;
    else
        offset = &offsets_stack.top();
    var_data sd = {type, *offset};
    ScopeTable &t = scopes_tables.back();
    t.insert(pair<string, var_data>(name, sd));
    if (isFunctionParameter)
        (*offset)--;
    else
        (*offset)++;
    return true;
}

void add_func(vector<int> param_types, tokens ret_type, const string& name) {
    func_data fd = {param_types, ret_type};
    if (func_table.find(name) != func_table.end()) {
        WRAP_ERROR(errorDef(yylineno, name));
    }
    func_table.insert(pair<string, func_data>(name, fd));
    func_names.push_back(name);
}

void tryAddVariable(stack_data *type_class, stack_data *id_class, bool func_var) {
    if (!addVariable(type_class, id_class, func_var)) {
        Id *id = dynamic_cast<Id *>(id_class);
        WRAP_ERROR(errorDef(yylineno, id->id));
    }
}

pair<int, int> getVariable(stack_data* stackData){
    Id* varId = dynamic_cast<Id*>(stackData);

    FOR_EACH(iter, vector<ScopeTable>, scopes_tables) {
        ScopeTable &t = *iter;
        if (t.find(varId->id) != t.end()) {
            var_data& varData = t[varId->id];
            return pair<int, int>(varData.type, varData.offset);
        }
    }
    return pair<int, int>(-1, -1);
}



tokens getVariableType(stack_data* stackData) {
    Id* varId = dynamic_cast<Id*>(stackData);

    FOR_EACH(iter, vector<ScopeTable>, scopes_tables) {
        ScopeTable &t = *iter;
        if (t.find(varId->id) != t.end()) {
            var_data& varData = t[varId->id];
            return varData.type;
        }
    }
    // Error
    WRAP_ERROR(errorUndef(yylineno, varId->id));
}

tokens getFunctionReturnType(stack_data* stackData) {
    Id* funId = dynamic_cast<Id*>(stackData);
    func_data& funcData = func_table[funId->id];
    return funcData.ret_type;
}

void verifyFunctionDefined(stack_data* stackData) {
    Id* functionId = dynamic_cast<Id*>(stackData);
    if (func_table.find(functionId->id) == func_table.end()) {
        WRAP_ERROR(errorUndefFunc(yylineno, functionId->id));
    }
}

void verifyRightParams(stack_data* func_name, stack_data* param_list){
    string functionId = dynamic_cast<Id*>(func_name)->id;
    vector<int>& params = dynamic_cast<TypesList*>(param_list)->params;
    vector<int>& real_params = func_table[functionId].param_types;
    vector<string> params_string;

    FOR_EACH(iter, vector<int>, real_params) {
        int type = *iter;
        string s = type_to_string[type];
        params_string.push_back(s);
    }

    if(!compare_types(real_params, params)){
        WRAP_ERROR(errorPrototypeMismatch(yylineno, functionId, params_string));
    }
}

void verifyVariableDefined(stack_data * stackData) {
    Id* varId = dynamic_cast<Id*>(stackData);
    if (!contains_var(varId->id)) {
        WRAP_ERROR(errorUndef(yylineno, varId->id));
    }
}

void verifyType(stack_data *stackData, int t) {
    Type* type = dynamic_cast<Type*>(stackData);
    if (type == NULL || !compare_types(type->type, t)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

void verifyByteSize(stack_data* stackData) {
    Id* num = dynamic_cast<Id*>(stackData);
    int value;
    istringstream(num->id) >> value;
    if (num == NULL || value > 255 || value < 0) {
        WRAP_ERROR(errorByteTooLarge(yylineno, num->id));
    }
}

void verifyIdType(stack_data* idStackData, stack_data* expStackData) {
    Id* id = dynamic_cast<Id*>(idStackData);
    Type* type = dynamic_cast<Type*>(expStackData);

    FOR_EACH(iter, vector<ScopeTable>, scopes_tables) {
        ScopeTable& t = *iter;
        if (t.find(id->id) != t.end()) {
            var_data& varData = t[id->id];
            if (!compare_types(varData.type, type->type)) {
                WRAP_ERROR(errorMismatch(yylineno));
            }
        }
    }
}

void verifyReturn(int type) {
    if (!compare_types(current_return_type, type)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

int verifyTypes(stack_data *stackData, int num, ...) {
    Type* type = dynamic_cast<Type*>(stackData);

    va_list arguments;

    va_start(arguments, num);           // Initializing arguments to store all values after num
    for ( int x = 0; x < num; x++) {
        int t = va_arg(arguments, int);
        if (type != NULL && compare_types(type->type,t) ) {
            return t;
        }
    }
    va_end(arguments);

    WRAP_ERROR(errorMismatch(yylineno));
    // Unreachable
    return -1;
}

void verifyBreak() {
    if (!in_while) {
        WRAP_ERROR(errorUnexpectedBreak(yylineno));
    }
}

void verifyContinue() {
    if (!in_while) {
        WRAP_ERROR(errorUnexpectedContinue(yylineno));
    }
}

void verifyMainFunction() {
    FuncTable::iterator iterator = func_table.find("main");
    if (iterator == func_table.end()                // main is not declared in code
        || !(*iterator).second.param_types.empty()  // main() has parameters (and shouldn't)
        || (*iterator).second.ret_type != VOID)     // Return type is not void
    {
        WRAP_ERROR(errorMainMissing());
    }
}

void addFunctionDeclaration(stack_data* retType, stack_data *idVarData, stack_data* typesList) {
    tokens ret_type = (tokens) dynamic_cast<Type*>(retType)->type;
    Id * idVar = dynamic_cast<Id*>(idVarData);
    string id = idVar->id;
    TypesList* func_params = dynamic_cast<TypesList*>(typesList);
    add_func(func_params->params, ret_type, id);
}

void yyerror(const char * err) {
    WRAP_ERROR(errorSyn(yylineno));
}

void concatenate_params(vector<int>& v, TypesList* t1, TypesList* t2){
    if(t1 != NULL){
        v.insert(v.end(), t1->params.begin(), t1->params.end());
    }
    if(t2 != NULL){
        v.insert(v.end(), t2->params.begin(), t2->params.end());
    }
}

string get_free_register(){
    if(free_registers.empty()){
        //do something
    }
    string free_reg = free_registers.front();
    free_registers.pop_front();
    return free_reg;
}

void free_register(string& reg){
    free_registers.push_front(reg);
}

int string_to_int(string str){
    stringstream s;
    int n;
    s << str;
    s >> n;
    return n;
}

string int_to_string(int n){
    stringstream s;
    s << n;
    return s.str();
}

void get_ID_reg(stack_data* ID){
    Id* id = static_cast<Id*>(ID);
    pair<int, int> p = getVariable(id);
    if(p.first != -1) {
        id->type.type = p.first;
        int offset = p.second;
        id->type.reg = int_to_string(offset) + "($fb)";
    }
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool from_memory(string s){
//    std::istringstream iss(s);
//    int num = 0;
//    bool b = (iss >> num).fail();
    return s.size() > 1 && s.at(1) != 's' && s.at(1) != 't' && !is_number(s);
}

void lw(string reg /*dest*/, string src)
{
    string s = "lw " + reg + ", " + src;
    code_buffer->emit(s);
}

void sw(string reg, string dest)
{
    string s = "sw " + reg + ", " + dest;
    code_buffer->emit(s);
}

void li(string dest, int num)
{
    string s = "li " + dest + ", " + int_to_string(num);
    code_buffer->emit(s);
}

void li(string dest, string num)
{
    string s = "li " + dest + ", " + num;
    code_buffer->emit(s);
}

void move_data(string dest, string src){
    string real_src = src;
    //dest is in memory, check source
    if(from_memory(src)){
        real_src = get_free_register();
        lw(real_src, src);
    }
    else if(is_number(src)){
        real_src = get_free_register();
        li(real_src, src);
    }
    sw(real_src, dest);
    if(real_src != src){
        free_register(real_src);
    }
}

void binop(Type* dest, Type* Rsrc, Type* src, string op){
    string sdest = dest->reg;
    string sRsrc = Rsrc->reg;
    string ssrc = src->reg;

    if(from_memory(sdest)){
        sdest = get_free_register();
    }
    if(from_memory(sRsrc)){
        sRsrc = get_free_register();
        lw(sRsrc, Rsrc->reg);
    }
    if(from_memory(ssrc)){
        ssrc = get_free_register();
        lw(ssrc, src->reg);
    }

    if(op == "+"){
        op = "add";
    }
    else if(op == "-"){
        op = "sub";
    }
    else if(op == "*"){
        op = "mul";
    }
    else{
        op = "div";
    }

    string s = op + " " + sdest + ", " + sRsrc + ", " + ssrc;
    code_buffer->emit(s);
    //cout << s << endl;

    if(sdest != dest->reg){
        sw(sdest, dest->reg);
    }
    if(sRsrc != Rsrc->reg){
        free_register(sRsrc);
    }
    if(ssrc != src->reg){
        free_register(ssrc);
    }
}

string get_reg_if_mem(Type* t){
    if(from_memory(t->reg)){
        string reg = get_free_register();
        lw(reg, t->reg);
        return reg;
    }
    return t->reg;
}

void bool_assignment(string dest, Type* t){
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

void initialize_free_registers(){
    for (int i = 0; i <= 7; ++i) {
        string num = int_to_string(i);
        free_registers.push_front("$t" + num);
        free_registers.push_front("$s" + num);
    }
    free_registers.push_front("$t8");
    free_registers.push_front("$t9");
}

int main(){
    int_convertables.insert(INT);
    int_convertables.insert(BYTE);
    int_convertables.insert(NUM);

    code_buffer = &CodeBuffer::instance();

    initialize_free_registers();

    func_param_offset = -1;
    offsets_stack.push(0);

    // Add library functions
    vector<int> v1;
    v1.push_back(STRING);
    add_func(v1, static_cast<tokens>(VOID), "print");
    vector<int> v2;
    v2.push_back(INT);
    add_func(v2, static_cast<tokens>(VOID), "printi");

    initizlize_type_to_string();

//#ifdef YYDEBUG
//    yydebug = 1;
//#endif

    return yyparse();
}

#endif //HW3_PARSER_H
