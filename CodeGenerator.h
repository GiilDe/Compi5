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

    vector<RegisterPool> registers;

    map<string, string> relop_map;
    map<string, string> binop_map;

    /**
     * Label counter for zero-division checks
     */
    int zdiv_check_counter;

    int str_count;

    void save_caller_registers() {
        if (registers.size() > 0) {
            RegisterPool& pool = registers.back();
            list<Register> used = pool.getUsedRegisters();
            for (list<Register>::iterator iter = used.begin(); iter != used.end(); ++iter) {
                push((*iter).name);
            }
        }
        // Save previous frame pointer
        push("$fp");
        // Save previous return address
        push("$ra");
    }

    void restore_caller_registers() {
        // Restore return address
        pop("$ra");
        // Restore frame pointer
        pop("$fp");

        list<Register> used = getUsedRegisters();
        // Restore in reverse order
        for (list<Register>::reverse_iterator iter = used.rbegin(); iter != used.rend(); ++iter) {
            pop((*iter).name);
        }
    }

    void procedureCalleeStart(string name, stack_data* preconds) {
        // Backup
//        int var_num = parser->scope_var_num * 4;
//        if (var_num > 0) {
//            string var_num_s = utils.intToString(var_num);
//            buffer->emit("sub $sp, $sp, " + var_num_s);
//        }

        Preconditions* preconditions = dynamic_cast<Preconditions*>(preconds);

        if (preconditions->preconditions_num > 0) {

            Register r = getFreeRegister();
            for (int i = 0; i < preconditions->preconditions_num; ++i) {
                Exp* exp = preconditions->preconditionExps[i];
                boolAssignment(r.name, exp->type);
                buffer->emit("beq $zero, " + r.name + " prcnd_" + name);
            }
            freeRegister(r.name);
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

    void emitPrecondCheck(string functionName) {
        string label = "prcnd_" + functionName;
        buffer->emitData(label + "_str" + ": .asciiz \"Precondition hasn't been satisfied for function " + functionName + "\"\n");

        buffer->emit(label + ":");
        buffer->emit("la $a0, " + label + "_str");
        buffer->emit("li $v0, 4");
        buffer->emit("syscall");
        buffer->emit("j halt");
    }

public:
    string current_while_label;

    explicit CodeGenerator(Parser* parser);

    void procedureCalleeEndMain() {
        buffer->emit("halt:");
        buffer->emit("li $v0, 10");
        buffer->emit("syscall");
        buffer->emit(".end main");
        buffer->emitData("msg: .asciiz  \"Error division by zero\\n\"");
    }

    void procedureCalleeEnd() {
        buffer->emit("jr $ra");
    }


    Register getFreeRegister() {
        RegisterPool& pool = registers.back();
        return pool.getFreeRegister();
    }

    Exp* boolFunc(stack_data* idData);

    Exp* boolId(stack_data* bData);

    void freeRegister(const string& name) {
        RegisterPool& pool = registers.back();
        pool.freeRegister(name);
    }

    list<Register> getUsedRegisters() {
        RegisterPool& pool = registers.back();
        return pool.getUsedRegisters();
    }

    void push_argument(stack_data* arg){
        Exp* argument = dynamic_cast<Exp*>(arg);
        Type* type = armu->type;
        if (type->type == BOOL) {
            Register reg = getFreeRegister();
            boolAssignment(reg.name, type);
            arguments.push_back(reg.name);
            type->reg = reg;
            // freeRegister(reg.name);
        } else {
            arguments.push_back(arg->type->reg.name);
        }
    }

    void function_call(Exp* funcExp, const stack_data* argumentsData){
        const ArgumentList* typesList = dynamic_cast<const ArgumentList*>(argumentsData);
        const vector<Exp*>& types = typesList->params;

        save_caller_registers();

        vector<string> arguments;

        FOR_EACH_CONST(iter, vector<Exp*>, types) {
            const Exp* arg = *iter;
            pair<int, int> varData = parser->getVariable(arg ? arg->id : NULL);
            if (varData.first == -1) {
                // Not a variable, so probably an expression
                // arguments.push_back(utils.intToString(offset * 4) + "($fp)");
                Type* type = arg->type;
                if (type->type == BOOL) {
                    Register reg = getFreeRegister();
                    boolAssignment(reg.name, type);
                    arguments.push_back(reg.name);
                    type->reg = reg;
                    // freeRegister(reg.name);
                } else {
                    arguments.push_back(arg->type->reg.name);
                }
            } else {
                int offset = varData.second;
                arguments.push_back(utils.intToString(-offset * 4) + "($fp)");
            }
        }

        for (int i = arguments.size(); i > 0; --i) {
            push(arguments[i-1]);
        }

//        if (arguments.size() > 0 )
//            buffer->emit("sub $fp, $sp, " + utils.intToString(4 * arguments.size()));

//        buffer->emit("sub $sp, $sp, 4");
        if (arguments.size() > 0 )
            buffer->emit("sub $fp, $sp, 4");

        registers.push_back(RegisterPool());


//        if (real_var_size > 0) {
//            buffer->emit("add $fp, $sp, " + var_num_s);
//        }

        // Jump to procedure
        buffer->emit("jal " + funcExp->id->id);

        registers.pop_back();

        // buffer->emit("add $fp, $sp, " + utils.intToString(4 * arguments.size()));

//        buffer->emit("add $sp, $sp, 4");

        int real_var_size = 4 * arguments.size();
        string var_num_s = utils.intToString(real_var_size);
        if (real_var_size > 0) {
            buffer->emit("add $sp, $sp, " + var_num_s);
        }

        restore_caller_registers();

        int funcReturnType = parser->getFunctionReturnType(funcExp->id);
        if (funcReturnType == BOOL) {
            Id *id = funcExp->id;
            string reg = "$v0";

            Type* b = funcExp->type;
            b->bool_exp = true;

            vector<int> true_list;
            vector<int> false_list;

            true_list.push_back(buffer->emit("bgt " + reg + ", $zero, " + " "));
            false_list.push_back(buffer->emit("j "));

            //if (reg != b_->type->reg.name) {
            //    freeRegister(reg);
            //}

            b->true_list = true_list;
            b->false_list = false_list;
        } else if (funcReturnType != VOID) {
            funcExp->type->reg = getFreeRegister();
            mov(funcExp->type->reg.name, "$v0");
        }
    }

    void newFunction(stack_data* funcIdData, stack_data* preconds) {
        Id* funcId = dynamic_cast<Id*>(funcIdData);
        string id = funcId->id;

        if (dynamic_cast<Preconditions*>(preconds)->preconditions_num > 0)
            emitPrecondCheck(id);

        buffer->emit(id + ":");
        if (id == "main") {
            buffer->emit("move $fp, $sp");
        }
        procedureCalleeStart(id, preconds);
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

    void doIf(stack_data* expData, stack_data *labelData) {
        string after_if_label = buffer->genLabel();
        string label_true = dynamic_cast<Label*>(labelData)->label;
        Type* t = dynamic_cast<Exp*>(expData)->type;
        buffer->bpatch(t->true_list, label_true);
        buffer->bpatch(t->false_list, after_if_label);
    }

    Type* doBreak();

    void doContinue();

    void emitZeroDivisionCheck(const string& src);
};


#endif //COMPI5_CODEGENERATOR_H
