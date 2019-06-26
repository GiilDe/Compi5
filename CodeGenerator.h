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

    void save_caller_registers() {
        list<Register> used = parser->getUsedRegisters();
        for (list<Register>::iterator iter = used.begin(); iter != used.end(); ++iter) {
            push((*iter).name);
        }
    }

    void restore_caller_registers() {
        list<Register> used = parser->getUsedRegisters();
        // Restore in reverse order
        for (list<Register>::reverse_iterator iter = used.rbegin(); iter != used.rend(); ++iter) {
            pop((*iter).name);
        }
    }

    void procedureCalleeStart() {
        // Backup
        int var_num = parser->scope_var_num * 4;
        if (var_num > 0) {
            string var_num_s = utils.intToString(var_num);
            buffer->emit("sub $sp, $sp, " + var_num_s);
        }
    }

    void emitPrint() {
        buffer->emit("print:");
        buffer->emit("lw $a0, 0($sp)");
        buffer->emit("li $v0, 4");
        buffer->emit("syscall");
        buffer->emit("jr $ra");
    }

    void emitPrinti() {
        buffer->emit("printi:");
        buffer->emit("lw $a0, 0($sp)");
        buffer->emit("li $v0, 1");
        buffer->emit("syscall");
        buffer->emit("jr $ra");
    }

public:
    explicit CodeGenerator(Parser* parser);

    void procedureCalleeEnd() {
        buffer->emit("jr $ra");
    }

    void function_call(Exp* funcExp, const stack_data* argumentsData){
        const ArgumentList* typesList = dynamic_cast<const ArgumentList*>(argumentsData);
        const vector<Exp*>& types = typesList->params;
        vector<string> arguments;

        FOR_EACH_CONST(iter, vector<Exp*>, types) {
            const Exp* arg = *iter;
            pair<int, int> varData = parser->getVariable(arg ? arg->id : NULL);
            if (varData.first == -1) {
                // Not a variable, so probably an expression
                // arguments.push_back(utils.intToString(offset * 4) + "($fp)");
                Type* type = arg->type;
                if (type->type == BOOL) {
                    Register reg = parser->getFreeRegister();
                    boolAssignment(reg.name, type);
                    arguments.push_back(reg.name);
                    parser->freeRegister(reg.name);
                } else {
                    arguments.push_back(arg->type->reg.name);
                }
            } else {
                int offset = varData.second;
                arguments.push_back(utils.intToString(offset * 4) + "($fp)");
            }
        }

        // save_caller_registers();

        // Save previous frame pointer
        push("$fp");
        // Save previous return address
        push("$ra");

        for (int i = 0; i < arguments.size(); ++i) {
            push(arguments[i]);
        }

        int real_var_size = 4 * arguments.size();
        string var_num_s = utils.intToString(real_var_size);
        if (real_var_size > 0) {
            buffer->emit("add $fp, $sp, " + var_num_s);
        }

        // Jump to procedure
        buffer->emit("jal " + funcExp->id->id);

        int funcReturnType = parser->getFunctionReturnType(funcExp->id);
        if (funcReturnType != VOID) {
            funcExp->type->reg = parser->getFreeRegister();
            mov(funcExp->type->reg.name, "$v0");
            parser->freeRegister(funcExp->type->reg.name);
        }

        if (real_var_size > 0) {
            buffer->emit("add $sp, $sp, " + var_num_s);
        }

        // Restore return address
        pop("$ra");
        // Restore frame pointer
        pop("$fp");

        // restore_caller_registers();
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

    // void freeRegister(const string& name);

    bool isFromMemory(const string& name);

    string getRegisterIfMemory(Type* t);

    Exp* assignRegisterToID(stack_data* idData);

    CodeBuffer * buf();

    void printBuffer();

    void lw(const Register& reg /*dest*/, const Register& src);

    void sw(const Register& reg, const Register& dest);

    void li(const Register& dest, int num);

    void li(const Register& dest, const string& num);

    void push(const string &src);

    void pop(const string& dest);

    void mov(const string &dest, const string &src);

    Exp* binop(int destType, stack_data *rSrcData, stack_data *srcData, stack_data* binopData);

    Exp* relop(stack_data* b1Data, stack_data* b2Data, stack_data* opData);

    Exp* boolTrue();

    Exp* boolFalse();

    Exp* boolAnd(stack_data* b1Data, stack_data* b2Data, stack_data* labelData);

    Exp* boolOr(stack_data* b1Data, stack_data* b2Data, stack_data* labelData);

    Exp* boolNot(stack_data* bData);

    Exp* newString(const string& val);

    void boolAssignment(const string& dest, Type *t);

    void doAssignOp(stack_data* expTypeData, stack_data* idData, int type);

    void doReturn(stack_data* retExp);

    Type* doBreak();

    void doContinue();

    void procedure();

    void emitZeroDivisionCheck(const string& src);

    void emitMain();

};


#endif //COMPI5_CODEGENERATOR_H
