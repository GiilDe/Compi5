//
// Created by Miki Mints on 2019-06-17.
//

#include "Parser.h"

static bool var_comp(const pair<string, var_data>& v1, const pair<string, var_data>& v2) {
    var_data d1 = v1.second;
    var_data d2 = v2.second;
    return d1.offset < d2.offset;
}

static bool var_comp_rev(const pair<string, var_data>& v1, const pair<string, var_data>& v2) {
    var_data d1 = v1.second;
    var_data d2 = v2.second;
    return d1.offset > d2.offset;
}

void Parser::newScope() {
    func_param_offset = -1;
    offsets_stack.push(offsets_stack.top());
    scopes_tables.push_back(ScopeTable());
}

void Parser::exitScope(bool isFuncScope, stack_data *name, stack_data *precondNum) {
    endScope();
    if (isFuncScope) {
        string id = dynamic_cast<Id *>(name)->id;
        int n = dynamic_cast<Preconditions *>(precondNum)->preconditions_num;
        printPreconditions(id, n);
    }
    int offset = offsets_stack.top();
    offsets_stack.pop();
    ScopeTable &vars_to_print = scopes_tables.back();
    vector<pair<string, var_data> > vars_pos;
    vector<pair<string, var_data> > vars_neg;

    for (map<string, var_data>::iterator i = vars_to_print.begin(); i != vars_to_print.end(); ++i) {
        pair<string, var_data> d = *i;
        var_data data = d.second;
        if (data.offset >= 0)
            vars_pos.push_back(d);
        else
            vars_neg.push_back(d);
    }

    sort(vars_pos.begin(), vars_pos.end(), var_comp);
    sort(vars_neg.begin(), vars_neg.end(), var_comp_rev);

    for (vector<pair<string, var_data> >::iterator j = vars_neg.begin(); j != vars_neg.end(); ++j) {
        pair<string, var_data> i = *j;
        printID(i.first, i.second.offset, utils.typeToString(i.second.type));
    }

    for (vector<pair<string, var_data> >::iterator j = vars_pos.begin(); j != vars_pos.end(); ++j) {
        pair<string, var_data> i = *j;
        printID(i.first, i.second.offset, utils.typeToString(i.second.type));
    }

    scopes_tables.pop_back();
}

void Parser::exitLastScope() {
    endScope();
    for(int i = 0; i < func_names.size(); i++){
        string& name = func_names[i];
        func_data data = func_table[name];
        string ret_type = utils.typeToString(data.ret_type);
        vector<string> args;
        for(vector<int>::iterator i = data.param_types.begin(); i != data.param_types.end(); ++i){
            int type = *i;
            args.push_back(utils.typeToString(type));
        }
        string s = makeFunctionType(ret_type, args);
        string to_print = name + " " + s + " " + "0";
        // cout << to_print << endl;
    }
}

bool Parser::containsVar(const string& name) const {
    for (vector<ScopeTable>::const_iterator i = scopes_tables.begin(); i != scopes_tables.end(); ++i) {
        const ScopeTable &t = *i;
        if (t.find(name) != t.end()) {
            return true;
        }
    }
    return false;
}

bool Parser::addVariable(stack_data *varType, stack_data *varId, bool isFunctionParameter) {
    Type *conv1 = dynamic_cast<Type *>(varType);
    Id *conv2 = dynamic_cast<Id *>(varId);

    tokens type = static_cast<tokens>(conv1->type);
    string name = conv2->id;

    if (containsVar(name) || func_table.find(name) != func_table.end()) {
        return false;
    }
    int *offset;
    if (isFunctionParameter)
        offset = &func_param_offset;
    else
        offset = &offsets_stack.top();
    var_data sd = {type, *offset};
    ScopeTable &t = scopes_tables.back();
    t[name] = sd;
    if (isFunctionParameter)
        (*offset)--;
    else
        (*offset)++;
    return true;
}

void Parser::tryAddVariable(stack_data *typeData, stack_data *idData, bool isFunctionParameter) {
    if (!addVariable(typeData, idData, isFunctionParameter)) {
        Id *id = dynamic_cast<Id *>(idData);
        WRAP_ERROR(errorDef(yylineno, id->id));
    }
}

pair<int, int> Parser::getVariable(stack_data* stackData){
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

tokens Parser::getVariableType(const stack_data* stackData) const {
    const Id* varId = dynamic_cast<const Id*>(stackData);

    FOR_EACH_CONST(iter, vector<ScopeTable>, scopes_tables) {
        const ScopeTable &t = *iter;
        if (t.find(varId->id) != t.end()) {
            const var_data& varData = t.at(varId->id);
            return varData.type;
        }
    }
    // Error
    WRAP_ERROR(errorUndef(yylineno, varId->id));
}

tokens Parser::getFunctionReturnType(stack_data* stackData) const {
    Id* funId = dynamic_cast<Id*>(stackData);
    const func_data& funcData = func_table.at(funId->id);
    return funcData.ret_type;
}

void Parser::setCurrentReturnType(stack_data* stackData) {
    current_return_type = dynamic_cast<Type*>(stackData)->type;
}

void Parser::verifyFunctionDefined(stack_data* stackData) const {
    Id* functionId = dynamic_cast<Id*>(stackData);
    if (func_table.find(functionId->id) == func_table.end()) {
        WRAP_ERROR(errorUndefFunc(yylineno, functionId->id));
    }
}

void Parser::verifyRightParams(stack_data* func_name, stack_data* param_list) const {
    string functionId = dynamic_cast<Id*>(func_name)->id;
    vector<int>& params = dynamic_cast<TypesList*>(param_list)->params;
    const vector<int>& real_params = func_table.at(functionId).param_types;
    vector<string> params_string;

    FOR_EACH_CONST(iter, vector<int>, real_params) {
        int type = *iter;
        string s = utils.typeToString(type);
        params_string.push_back(s);
    }

    if(!compare_types(real_params, params)) {
        WRAP_ERROR(errorPrototypeMismatch(yylineno, functionId, params_string));
    }
}

void Parser::verifyVariableDefined(stack_data * stackData) const {
    Id* varId = dynamic_cast<Id*>(stackData);
    if (!containsVar(varId->id)) {
        WRAP_ERROR(errorUndef(yylineno, varId->id));
    }
}

void Parser::verifyType(stack_data *stackData, int t) const {
    Type* type = dynamic_cast<Type*>(stackData);
    if (type == NULL || !utils.isAssignable(type->type, t)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

void Parser::verifyByteSize(stack_data* stackData) const {
    Id* num = dynamic_cast<Id*>(stackData);
    int value;
    istringstream(num->id) >> value;
    if (num == NULL || value > 255 || value < 0) {
        WRAP_ERROR(errorByteTooLarge(yylineno, num->id));
    }
}

void Parser::verifyIdType(stack_data* idStackData, stack_data* expStackData) const {
    Id* id = dynamic_cast<Id*>(idStackData);
    Type* type = dynamic_cast<Type*>(expStackData);

    FOR_EACH_CONST(iter, vector<ScopeTable>, scopes_tables) {
        const ScopeTable& t = *iter;
        if (t.find(id->id) != t.end()) {
            const var_data& varData = t.at(id->id);
            if (!utils.isAssignable(varData.type, type->type)) {
                WRAP_ERROR(errorMismatch(yylineno));
            }
        }
    }
}

void Parser::verifyReturn(int type) const {
    if (!utils.isAssignable(current_return_type, type)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

int Parser::verifyTypes(stack_data *stackData, int num, ...) const {
    Type* type = dynamic_cast<Type*>(stackData);

    va_list arguments;

    va_start(arguments, num);           // Initializing arguments to store all values after num
    for ( int x = 0; x < num; x++) {
        int t = va_arg(arguments, int);
        if (type != NULL && utils.isAssignable(type->type,t) ) {
            return t;
        }
    }
    va_end(arguments);

    WRAP_ERROR(errorMismatch(yylineno));
    // Unreachable
    return -1;
}

void Parser::verifyBreak() const {
    if (!in_while) {
        WRAP_ERROR(errorUnexpectedBreak(yylineno));
    }
}

void Parser::verifyContinue() const {
    if (!in_while) {
        WRAP_ERROR(errorUnexpectedContinue(yylineno));
    }
}

void Parser::verifyMainFunction() const {
    FuncTable::const_iterator iterator = func_table.find("main");
    if (iterator == func_table.end()                // main is not declared in code
        || !(*iterator).second.param_types.empty()  // main() has parameters (and shouldn't)
        || (*iterator).second.ret_type != VOID)     // Return type is not void
    {
        WRAP_ERROR(errorMainMissing());
    }
}

void Parser::addFunctionDeclaration(stack_data* retType, stack_data *idVarData, stack_data* typesList) {
    tokens ret_type = (tokens) dynamic_cast<Type*>(retType)->type;
    Id * idVar = dynamic_cast<Id*>(idVarData);
    string id = idVar->id;
    TypesList* func_params = dynamic_cast<TypesList*>(typesList);
    addFunction(func_params->params, ret_type, id);
}

void Parser::addFunction(vector<int> param_types, tokens ret_type, const string& name) {
    func_data fd = {param_types, ret_type};
    if (func_table.find(name) != func_table.end()) {
        WRAP_ERROR(errorDef(yylineno, name));
    }
    func_table.insert(pair<string, func_data>(name, fd));
    func_names.push_back(name);
}

void Parser::inWhile() {
    in_while++;
}

void Parser::outWhile() {
    in_while--;
}

Parser::Parser(Utils& utils) :
        utils(utils),
        scopes_tables(),
        offsets_stack(),
        func_names(),
        in_while(0),
        func_param_offset(-1),
        current_return_type(0) {

    offsets_stack.push(0);

    // Add library functions
    vector<int> v1;
    v1.push_back(STRING);
    addFunction(v1, static_cast<tokens>(VOID), "print");
    vector<int> v2;
    v2.push_back(INT);
    addFunction(v2, static_cast<tokens>(VOID), "printi");
}
