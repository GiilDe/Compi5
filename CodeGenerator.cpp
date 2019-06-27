//
// Created by Miki Mints on 2019-06-17.
//

#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(Parser* parser) :
        buffer(&CodeBuffer::instance()),
        parser(parser),
        utils(),
        relop_map(),
        binop_map(),
        zdiv_check_counter(0),
        str_count(0),
        registers() {

    for (int i = 0; i <= 7; ++i) {
        string num = utils.intToString(i);
        free_registers.push_front("$t" + num);
        free_registers.push_front("$s" + num);
    }
    free_registers.push_front("$t8");
    free_registers.push_front("$t9");

    relop_map[">="] = "bge";
    relop_map[">"] = "bgt";
    relop_map["<="] = "ble";
    relop_map["<"] = "blt";
    relop_map["=="] = "beq";
    relop_map["!="] = "bne";

    binop_map["+"] = "addu";
    binop_map["-"] = "sub";
    binop_map["*"] = "mul";
    binop_map["/"] = "div";

    buffer->emit(".globl main");
    buffer->emit(".ent main");

    emitPrint();
    emitPrinti();
    registers.push_back(RegisterPool());
}


void CodeGenerator::lw(const Register &reg /*dest*/, const Register &src) {
    string s = "lw " + reg.name + ", " + src.name;
    buffer->emit(s);
}

void CodeGenerator::sw(const Register &reg, const Register &dest) {
    string s = "sw " + reg.name + ", " + dest.name;
    buffer->emit(s);
}

void CodeGenerator::li(const Register &dest, int num) {
    string s = "li " + dest.name + ", " + utils.intToString(num);
    buffer->emit(s);
}

void CodeGenerator::li(const Register &dest, const string &num) {
    string s = "li " + dest.name + ", " + num;
    buffer->emit(s);
}

void CodeGenerator::push(const string &src) {
    buffer->emit("sub $sp, $sp, 4");
    mov("0($sp)", src);
}

void CodeGenerator::pop(const string& dest) {
    buffer->emit("lw " + dest + ", 0($sp)");
    buffer->emit("add $sp, $sp, 4");
}

void CodeGenerator::mov(const string &dest, const string &src) {
    string real_src = src;
    // dest is in memory, check source
    if (isFromMemory(src)) {
        real_src = getFreeRegister().name;
        lw(real_src, src);
    } else if (utils.isNumber(src)) {
        real_src = getFreeRegister().name;
        li(real_src, src);
    }
    if (isFromMemory(dest)) {
        sw(real_src, dest);
    } else {
        buffer->emit("add " + dest + ", $zero, " + real_src);
    }
    if (real_src != src) {
        freeRegister(real_src);
    }
}

Exp* CodeGenerator::binop(int destType, stack_data *rSrcData, stack_data *srcData, stack_data* binopData) {
    Type* dest = new Type(destType);
    dest->reg = getFreeRegister();

    Exp* Rexp = dynamic_cast<Exp*>(rSrcData);
    Exp* exp = dynamic_cast<Exp*>(srcData);

    Type* Rsrc = Rexp->type;
    Type* src = exp->type;
    Binop* binop = dynamic_cast<Binop*>(binopData);

    string sdest = dest->reg.name;
    string sRsrc = Rsrc->reg.name;
    string ssrc = src->reg.name;

    if (isFromMemory(sdest)) {
        sdest = getFreeRegister().name;
    }
    if (isFromMemory(sRsrc)) {
        sRsrc = getFreeRegister().name;
        lw(sRsrc, Rsrc->reg.name);
    }
    if (isFromMemory(ssrc)) {
        ssrc = getFreeRegister().name;
        lw(ssrc, src->reg.name);
    }

    if (binop->op == "/") {
        emitZeroDivisionCheck(ssrc);
    }

    if (utils.isNumber(sRsrc)) {
        string newRsrc = getFreeRegister().name;
        buffer->emit("li " + newRsrc + ", " + sRsrc);
        sRsrc = newRsrc;
    }
    buffer->emit(binop_map.at(binop->op) + " " + sdest + ", " + sRsrc + ", " + ssrc);

    if (destType == BYTE) {
        // Truncate
        buffer->emit("and " + sdest + " " + sdest + " 0xff");
    }

    //cout << s << endl;

    if (sdest != dest->reg.name) {
        sw(sdest, dest->reg);
    }
    freeRegister(sRsrc);
    freeRegister(ssrc);

    return new Exp(dest);
}

Exp* CodeGenerator::relop(stack_data* b1Data, stack_data* b2Data, stack_data* opData) {
    Exp* b1 = dynamic_cast<Exp*>(b1Data);
    Exp* b2 = dynamic_cast<Exp*>(b2Data);
    string op = dynamic_cast<Binop*>(opData)->op;

    string reg1 = getRegisterIfMemory(b1->type);
    string reg2 = getRegisterIfMemory(b2->type);

    Type* b = new Type(BOOL);
    b->bool_exp = true;

    vector<int> true_list;
    vector<int> false_list;

    true_list.push_back(buffer->emit(relop_map.at(op) + " " + reg1 + ", " + reg2 + " "));
    false_list.push_back(buffer->emit("j "));

    if (reg1 != b1->type->reg.name) {
        freeRegister(reg1);
    }

    if (reg2 != b2->type->reg.name) {
        freeRegister(reg2);
    }

    b->true_list = true_list;
    b->false_list = false_list;

    return new Exp(b);
}

Exp* CodeGenerator::boolTrue() {
    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list.push_back(buffer->emit("j "));
    return new Exp(b);
}

Exp* CodeGenerator::boolFalse() {
    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->false_list.push_back(buffer->emit("j "));
    return new Exp(b);
}

Exp* CodeGenerator::boolAnd(stack_data* b1Data, stack_data* b2Data, stack_data* labelData) {
    Type* b1 = dynamic_cast<Exp*>(b1Data)->type;
    Type* b2 = dynamic_cast<Exp*>(b2Data)->type;
    string label = dynamic_cast<Label*>(labelData)->label;
    buffer->bpatch(b1->true_list, label);

    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list = b2->true_list;
    b->false_list = buffer->merge(b1->false_list, b2->false_list);

    return new Exp(b);
}

Exp* CodeGenerator::boolOr(stack_data* b1Data, stack_data* b2Data, stack_data* labelData) {
    Type* b1 = dynamic_cast<Exp*>(b1Data)->type;
    Type* b2 = dynamic_cast<Exp*>(b2Data)->type;
    string label = dynamic_cast<Label*>(labelData)->label;
    buffer->bpatch(b1->false_list, label);

    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list = buffer->merge(b1->true_list, b2->true_list);
    b->false_list = b2->false_list;

    return new Exp(b);
}

Exp* CodeGenerator::boolId(stack_data* idData){
    assignRegisterToID(idData);
    Id *id = dynamic_cast<Id*>(idData);
    string reg = id->type.reg.name;

    Type* b = new Type(BOOL);
    b->bool_exp = true;

    vector<int> true_list;
    vector<int> false_list;

    true_list.push_back(buffer->emit("bgt " + reg + "0" + " "));
    false_list.push_back(buffer->emit("j "));

    //if (reg != b_->type->reg.name) {
    //    freeRegister(reg);
    //}

    b->true_list = true_list;
    b->false_list = false_list;

    return new Exp(b);
}

Exp* CodeGenerator::boolNot(stack_data* bData) {
    Type* b = new Type(BOOL);

    Type* b1 = dynamic_cast<Exp*>(bData)->type;

    b->bool_exp = true;
    b->false_list = b1->true_list;
    b->true_list = b1->false_list;

    return new Exp(b);
}

//string CodeGenerator::getFreeRegister() {
//    if (free_registers.empty()) {
//        //do something
//    }
//    string free_reg = free_registers.front();
//    free_registers.pop_front();
//    return free_reg;
//}

//void CodeGenerator::freeRegister(const string &name) {
//    free_registers.push_front(name);
//}

bool CodeGenerator::isFromMemory(const string &name) {
    return name.size() > 1
            && name.at(1) != 's'
            && name.at(1) != 't'
            && name != "$fp"
            && name != "$ra"
            && name != "$v0"
            && !utils.isNumber(name);
}

string CodeGenerator::getRegisterIfMemory(Type *t) {
    string name = t->reg.name;
    if (isFromMemory(name)) {
        Register reg = getFreeRegister();
        lw(reg, t->reg);
        return reg.name;
    }
    if (utils.isNumber(name)) {
        Register reg = getFreeRegister();
        li(reg, name);
        return reg.name;
    }
    return t->reg.name;
}

Exp* CodeGenerator::assignRegisterToID(stack_data *idData) {
    Id *id = dynamic_cast<Id *>(idData);
    pair<int, int> p = parser->getVariable(id);
    if (p.first != -1) {
        id->type.type = p.first;
        // Align offset to 4 bytes
        int offset = -4 * p.second;
        id->type.reg = utils.intToString(offset) + "($fp)";
    }

    return new Exp(id, new Type(parser->getVariableType(idData), id->type.reg.name));
}

void CodeGenerator::boolAssignment(const string& dest, Type *t) {
    string T = buffer->genLabel();
    mov(dest, "1");
    int skip_F_jump = buffer->emit("j ");
    string F = buffer->genLabel();
    mov(dest, "0");
    string after_F = buffer->genLabel();
    buffer->bpatch(buffer->makelist(skip_F_jump), after_F);
    buffer->bpatch(t->true_list, T);
    buffer->bpatch(t->false_list, F);
}

CodeBuffer *CodeGenerator::buf() {
    return buffer;
}

void CodeGenerator::printBuffer() {
    buffer->printDataBuffer();
    buffer->printCodeBuffer();
}

void CodeGenerator::doAssignOp(stack_data *expTypeData, stack_data *idData, int type) {
    Exp *expType = dynamic_cast<Exp *>(expTypeData);
    assignRegisterToID(idData);
    Id *id = dynamic_cast<Id*>(idData);
    string dest = id->type.reg.name;
    if (type != BOOL) {
        if (expType == NULL) {
            mov(dest, "0");
        } else {
            mov(dest, expType->type->reg.name);
        }
    } else {
        if (expType == NULL) {
            Exp *exp = new Exp(id, new Type(BOOL));
            boolAssignment(dest, exp->type);
        } else {
            boolAssignment(dest, expType->type);
        }
    }
}

Exp* CodeGenerator::newString(const string &val) {
    // Add string to data section
    string label = "str" + utils.intToString(str_count);
    buffer->emitData(label + ": .asciiz " + val);

    string reg = getFreeRegister().name;
    buffer->emit("la " + reg + ", " + label);

    str_count++;
    return new Exp(new Type(STRING, reg));
}

void CodeGenerator::doReturn(stack_data *retExpData) {
    int type;
    if (retExpData == NULL) {
        type = VOID;
    } else {
        Exp * retExp = dynamic_cast<Exp*>(retExpData);
        type = retExp->type->type;

        if (type == BOOL) {
            boolAssignment("$v0", retExp->type);
        } else {
            mov("$v0", retExp->type->reg.name);
        }
    }
    parser->verifyReturn(type);
    procedureCalleeEnd();
}

Type* CodeGenerator::doBreak() {
    parser->verifyBreak();

    Type * t = new Type(VOID);
    t->exit_list.push_back(buffer->emit("j "));

    return t;
}

void CodeGenerator::doContinue() {
    parser->verifyContinue();
    buffer->emit("j " + current_while_label);
}

void CodeGenerator::emitZeroDivisionCheck(const string& src) {
    string counter = utils.intToString(zdiv_check_counter);
    string dbzLabel = "dbz" + counter;
    string ndbzLabel = "ndbz" + counter;

    string real_src = src;
    if (utils.isNumber(src)) {
        real_src = getFreeRegister().name;
        mov(real_src, src);
    }
    buffer->emit("beq " + real_src + ", $zero, " + dbzLabel);
    // freeRegister(real_src);
    buffer->emit("j " + ndbzLabel);

    buffer->emit(dbzLabel + ":");
    li(Register("$v0"), 4);
    buffer->emit("la $a0, msg");
    buffer->emit("syscall");
    buffer->emit("j halt");

    buffer->emit(ndbzLabel + ":");
    zdiv_check_counter++;
}

void CodeGenerator::emitMain() {
//    buffer->emit("main:");
//    buffer->emit("move $fp, $sp");
//
//    buffer->emit("jal " + string(START_FUN));
//
//    buffer->emit("halt:");
//    buffer->emit("li $v0, 10");
//    buffer->emit("syscall");
//    buffer->emit(".end main");
//    buffer->emitData("msg: .asciiz  \"Error division by zero\\n\"");
}
