//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_MIPSWRAPPER_H
#define COMPI5_MIPSWRAPPER_H


#include <bp.hpp>
#include "Utils.h"
#include "Parser.h"
#include <list>

using std::list;

class MipsWrapper {

private:
    CodeBuffer* buffer;
    Parser parser;
    Utils utils;

    list<string> free_registers;

public:
    explicit MipsWrapper(Parser& parser);

    void lw(const string& reg /*dest*/, const string& src);

    void sw(const string& reg, const string& dest);

    void li(const string& dest, int num);

    void li(const string& dest, const string& num);

    void binop(Type *dest, Type *Rsrc, Type *src, string op);

    string getFreeRegister();

    void freeRegister(const string& name);

    bool isFromMemory(const string& name);

    void moveData(const string& dest, const string& src);

    string getRegisterIfMemory(Type* t);

    void assignRegisterToID(stack_data* idData);

    void boolAssignment(const string& dest, Type *t);

    void doAssignOp(stack_data* expTypeData, stack_data* idData, int type);

    CodeBuffer * buf();

    void printCodeBuffer();

};


#endif //COMPI5_MIPSWRAPPER_H
