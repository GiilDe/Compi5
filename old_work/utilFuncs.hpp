#ifndef UTILFUNCS_HPP
#define UTILFUNCS_HPP
#include "parser.hpp"
#include "output.hpp"
#include <math.h>
#include <string>
#include <string.h>
#include <map>
using namespace std;

bool typeCheck(Type type1, Type type2) {
    if (type1 == type2)
        return true;
    if ((type1 == INT_TYPE || type1 == BYTE_TYPE) && (type2 == INT_TYPE || type2 == BYTE_TYPE))
        return true;
    return false;
}

string typeToString(Type type) {
    switch (type) {
        case INT_TYPE:
            return "INT";
            break;
        case STRING_TYPE:
            return "STRING";
            break;
        case BOOL_TYPE:
            return "BOOL";
            break;
        case BYTE_TYPE:
            return "BYTE";
            break;
        case STRUCT_TYPE:
            return "STRUCT";
            break;
        case VOID_TYPE:
            return "VOID";
            break;
    }
    return "Err";
}

Type stringToType(string type) {
    map<string, int> temp;
    temp.insert(pair<string, int>("INT", 0));
    temp.insert(pair<string, int>("STRING", 1));
    temp.insert(pair<string, int>("BYTE", 2));
    temp.insert(pair<string, int>("BOOL", 3));
    temp.insert(pair<string, int>("STRUCT", 4));
    temp.insert(pair<string, int>("VOID", 5));

    map<string, int>::iterator i = temp.find(type);
    if (i == temp.end()) {
        return STRUCT_ID_TYPE;
    }
    return Type(temp.at(type));
}


bool typeCheck(Type type1, Type type2, Type type3) {
    return (typeCheck(type1, type2) && (type1 == type3));
}

bool checkTypeAssign(string lval, ExpClass rval) {
    if (rval.exp_type != STRUCT_ID_TYPE) {
        if (lval == typeToString(rval.exp_type))
            return true;
        if (typeToString(rval.exp_type) == "BYTE" && lval == "INT")
            return true;
        return false;
    }
    if (lval == *(rval.id))
        return true;
    return false;
}

bool compareVectorTypes(vector<string> *funcTypes, vector<ExpClass *> *parametersTypes) {
    if (funcTypes->size() != parametersTypes->size())
        return false;
    vector<string>::iterator i1 = funcTypes->begin();
    vector<ExpClass *>::reverse_iterator i2 = parametersTypes->rbegin();
    while (i1 != funcTypes->end()) {
        if (!checkTypeAssign((*i1), (*(*i2))))
            return false;
        i1++;
        i2++;
    }
    return true;
}

bool isInlist(vector<MemStruct *> *ls, MemStruct *mem) {
    vector<MemStruct *>::iterator i = ls->begin();
    while (i != ls->end()) {
        if (*(mem->id) == *((*i)->id))
            return true;
        i++;
    }
    return false;
}

bool isInlist(vector<FormalDec *> *ls, FormalDec *dec) {
    vector<FormalDec *>::iterator i = ls->begin();
    while (i != ls->end()) {
        if (*(dec->id) == *((*i)->id))
            return true;
        i++;
    }
    return false;
}

void printExp(ExpClass *exp) {
    cout << typeToString(exp->exp_type) << " ";
    if (exp->id != NULL)
        cout << exp->id;
    cout << exp->value << endl;
}

void printMem(MemStruct *mem) {
    if (mem->id == NULL)
        cout << "NULL!!!" << endl;
    cout << typeToString(mem->type) << " " << *(mem->id) << endl;
}

void printDec(FormalDec *dec) {
    cout << typeToString(dec->type) << " " << dec->struct_type << " " << dec->id << endl;
}

void printExpList(vector<ExpClass *> *list) {
    vector<ExpClass *>::iterator it = list->begin();
    while (it != list->end()) {
        printExp((*it));
        it++;
    }
}

void printMemList(vector<MemStruct *> *list) {
    vector<MemStruct *>::iterator it = list->begin();
    while (it != list->end()) {
        printMem((*it));
        it++;
    }
}

void printDecList(vector<FormalDec *> *list) {
    vector<FormalDec *>::iterator it = list->begin();
    while (it != list->end()) {
        printDec((*it));
        it++;
    }
}

ExpClass *copyExpClass(ExpClass *exp) {
    ExpClass *new_exp = new ExpClass();
    new_exp->value = exp->value;
    if (exp->id != NULL)
        new_exp->id = new string(*(exp->id));
    new_exp->exp_type = exp->exp_type;
    new_exp->reg = exp->reg;
    if(exp->Tlist != NULL)
        new_exp->Tlist = new vector<int>(*exp->Tlist);
    if(exp->Flist != NULL)
        new_exp->Flist = new vector<int>(*exp->Flist);
    if(exp->structVarName != NULL)
        new_exp->structVarName = new string(*(exp->structVarName));
    return new_exp;
}

MemStruct *copyMemStruct(MemStruct *mem) {
    MemStruct *new_mem = new MemStruct();
    new_mem->id = new string(*(mem->id));
    new_mem->type = mem->type;
    return new_mem;
}

FormalDec *copyDec(FormalDec *dec) {
    FormalDec *new_dec = new FormalDec();
    new_dec->id = new string(*(dec->id));
    new_dec->type = dec->type;
    if (dec->struct_type != NULL)
        new_dec->struct_type = new string(*(dec->struct_type));
    return new_dec;
}

vector<int>* vectorMerge(vector<int>* dest, vector<int>* src)
{
    if(dest != NULL && src != NULL)
    {
        dest->insert(dest->begin(), src->begin(), src->end());
        return dest;
    }
    if(dest == NULL)
    {
        return src;
    }
}













#endif