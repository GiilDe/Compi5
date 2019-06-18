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

    /**
     * Label counter for zero-division checks
     */
    int zdiv_check_counter;

    void procedureCallerBefore(const string& id, const vector<string>& arguments) {
        for (int i = 0; i < arguments.size(); ++i) {
            push(arguments[i]);
        }
        push("$fp");
        buffer->emit("jal " + id);
    }

    void procedureCallerAfter(int var_num) {
        pop("$fp");
        int real_var_size = 4*var_num;
        string var_num_s = utils.intToString(real_var_size);
        buffer->emit("addi " + var_num_s + ", $sp");
    }

    void save_callee_registers(){
    }

    void restore_callee_registers(){
    }

    void procedureCalleeStart() {
        int var_num = parser->scope_var_num * 4;
        string var_num_s = utils.intToString(var_num);
        save_callee_registers();
        buffer->emit("subi " + var_num_s + ", $sp");
    }

    void procedureCalleeEnd() {
        restore_callee_registers();
        buffer->emit("move $sp, $fp");
        pop("$ra");
        buffer->emit("jr $ra");
    }

public:
    explicit CodeGenerator(Parser* parser);

    string getFreeRegister();

    void function_call(const string& id, const stack_data* argumentsData){
        const ArgumentList* typesList = dynamic_cast<const ArgumentList*>(argumentsData);
        const vector<Argument*>& types = *typesList->params;
        vector<string> arguments;

        FOR_EACH_CONST(iter, vector<Argument*>, types) {
            const Argument* arg = *iter;
            pair<int, int> varData = parser->getVariable(arg->id);
            if (varData.first == -1) {
                // Not a variable, so probably an expression
            }
            int offset = varData.second;
        }

        procedureCallerBefore(id, arguments);
//        procedureCalleeStart();
//        procedureCalleeEnd();
        procedureCallerAfter(arguments.size());
    }

    void newFunction(stack_data* funcIdData) {
        Id* funcId = dynamic_cast<Id*>(funcIdData);
        string id = funcId->id;

        if (id == "main") {
            id = "__start"; // Wrap main function
        }
        buffer->emit(id + ":");
        procedureCalleeStart();
        procedureCalleeEnd();
    }

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

    void push(const string &src);

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

    void procedure();

    void emitZeroDivisionCheck(const string& src);

    void emitMain();

};


#endif //COMPI5_CODEGENERATOR_H
