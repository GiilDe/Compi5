//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_CODEGENERATOR_H
#define COMPI5_CODEGENERATOR_H


#include "bp.hpp"
#include "Utils.h"
#include "Parser.h"
#include <list>

using std::list;

#define START_FUN "__start_main"

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

    int str_count;

    void save_callee_registers(){
    }

    void restore_callee_registers(){
    }

    void procedureCalleeStart() {
        // Backup
        int var_num = parser->scope_var_num * 4;
        save_callee_registers();
        if (var_num > 0) {
            string var_num_s = utils.intToString(var_num);
            buffer->emit("sub $sp, $sp, " + var_num_s);
        }
        buffer->emit("move $fp, $sp");
    }

    void emitPrint() {
        buffer->emit("print:");
        buffer->emit("lw $a0, 0($sp)");
        buffer->emit("li $v0, 1");
        buffer->emit("syscall");
        buffer->emit("jr $ra");
    }

    void emitPrinti() {
        buffer->emit("printi:");
        buffer->emit("lw $a0, 0($sp)");
        buffer->emit("li $v0, 4");
        buffer->emit("syscall");
        buffer->emit("jr $ra");
    }

public:
    explicit CodeGenerator(Parser* parser);

    string getFreeRegister();

    void procedureCalleeEnd() {
        restore_callee_registers();
        buffer->emit("move $sp, $fp");
        buffer->emit("jr $ra");
        buffer->emit("add $sp, $sp, 4");
        buffer->emit("lw $ra, 0($sp)");
    }

    void function_call(const string& id, const stack_data* argumentsData){
        const ArgumentList* typesList = dynamic_cast<const ArgumentList*>(argumentsData);
        const vector<Argument*>& types = typesList->params;
        vector<string> arguments;

        FOR_EACH_CONST(iter, vector<Argument*>, types) {
            const Argument* arg = *iter;
            pair<int, int> varData = parser->getVariable(arg->id);
            if (varData.first == -1) {
                // Not a variable, so probably an expressionw
            }
            int offset = varData.second;
            arguments.push_back(utils.intToString(offset * 4) + "($fp)");
        }

        // Save previous frame pointer
        push("$fp");
        // Save previous return address
        push("$ra");

        for (int i = 0; i < arguments.size(); ++i) {
            push(arguments[i]);
        }

        // Jump to procedure
        buffer->emit("jal " + id);

        int real_var_size = 4 * arguments.size();
        if (real_var_size > 0) {
            string var_num_s = utils.intToString(real_var_size);
            buffer->emit("add $sp, $sp, " + var_num_s);
        }

        // Restore return address
        pop("$ra");
        // Restore frame pointer
        pop("$fp");
    }

    void newFunction(stack_data* funcIdData) {
        Id* funcId = dynamic_cast<Id*>(funcIdData);
        string id = funcId->id;

        if (id == "main") {
            id = START_FUN; // Wrap main function
        }
        buffer->emit(id + ":");
        procedureCalleeStart();
    }

    void freeRegister(const string& name);

    bool isFromMemory(const string& name);

    string getRegisterIfMemory(Type* t);

    Type* assignRegisterToID(stack_data* idData);

    CodeBuffer * buf();

    void printBuffer();

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

    Type* newString(const string& val);

    void doReturn(stack_data* retExp);

    void procedure();

    void emitZeroDivisionCheck(const string& src);

    void emitMain();

};


#endif //COMPI5_CODEGENERATOR_H
