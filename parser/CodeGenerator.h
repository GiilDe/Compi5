//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_CODEGENERATOR_H
#define COMPI5_CODEGENERATOR_H


#include "../bp.hpp"
#include "Utils.h"
#include "Parser.h"
#include <list>

using std::list;

class CodeGenerator {

private:
    CodeBuffer* buffer;
    Parser* parser;
    Utils utils;

    list<string> free_registers;

    map<string, string> relop_map;
    map<string, string> binop_map;

public:
    explicit CodeGenerator(Parser* parser);

    string getFreeRegister();

    void freeRegister(const string& name);

    bool isFromMemory(const string& name);

    string getRegisterIfMemory(Type* t);

    void assignRegisterToID(stack_data* idData);

    CodeBuffer * buf();

    void printCodeBuffer();

    void lw(const string& reg /*dest*/, const string& src);

    void sw(const string& reg, const string& dest);

    void li(const string& dest, int num);

    void li(const string& dest, const string& num);

    void push(const string &dest);

    void pop(const string& dest);

    void mov(const string &dest, const string &src);

    Type* binop(int destType, stack_data *rSrcData, stack_data *srcData, stack_data* binopData);

    Type* relop(stack_data* b1Data, stack_data* b2Data, stack_data* opData);

    Type* boolTrue();

    Type* boolFalse();

    Type* boolAnd(stack_data* b1Data, stack_data* b2Data, stack_data* labelData);

    Type* boolOr(stack_data* b1Data, stack_data* b2Data, stack_data* labelData);

    Type* boolNot(stack_data* bData);

    void boolAssignment(const string& dest, Type *t);

    void doAssignOp(stack_data* expTypeData, stack_data* idData, int type);

};


#endif //COMPI5_CODEGENERATOR_H
