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
        str_count(0) {

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

    binop_map["+"] = "add";
    binop_map["-"] = "sub";
    binop_map["*"] = "mul";
    binop_map["/"] = "div";

    buffer->emit(".globl main");
    buffer->emit(".ent main");

    emitPrint();
    emitPrinti();
}


void CodeGenerator::lw(const string &reg /*dest*/, const string &src) {
    string s = "lw " + reg + ", " + src;
    buffer->emit(s);
}

void CodeGenerator::sw(const string &reg, const string &dest) {
    string s = "sw " + reg + ", " + dest;
    buffer->emit(s);
}

void CodeGenerator::li(const string &dest, int num) {
    string s = "li " + dest + ", " + utils.intToString(num);
    buffer->emit(s);
}

void CodeGenerator::li(const string &dest, const string &num) {
    string s = "li " + dest + ", " + num;
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
        real_src = getFreeRegister();
        lw(real_src, src);
    } else if (utils.isNumber(src)) {
        real_src = getFreeRegister();
        li(real_src, src);
    }
    sw(real_src, dest);
    if (real_src != src) {
        freeRegister(real_src);
    }
}

Type* CodeGenerator::binop(int destType, stack_data *rSrcData, stack_data *srcData, stack_data* binopData) {
    Type* dest = new Type(destType);
    dest->reg = getFreeRegister();

    Type* Rsrc = dynamic_cast<Type*>(rSrcData);
    Type* src = dynamic_cast<Type*>(srcData);
    Binop* binop = dynamic_cast<Binop*>(binopData);

    string sdest = dest->reg;
    string sRsrc = Rsrc->reg;
    string ssrc = src->reg;

    if (isFromMemory(sdest)) {
        sdest = getFreeRegister();
    }
    if (isFromMemory(sRsrc)) {
        sRsrc = getFreeRegister();
        lw(sRsrc, Rsrc->reg);
    }
    if (isFromMemory(ssrc)) {
        ssrc = getFreeRegister();
        lw(ssrc, src->reg);
    }

    if (binop->op == "/") {
        emitZeroDivisionCheck(ssrc);
    }

    buffer->emit(binop_map.at(binop->op) + " " + sdest + ", " + sRsrc + ", " + ssrc);
    //cout << s << endl;

    if (sdest != dest->reg) {
        sw(sdest, dest->reg);
    }
    if (sRsrc != Rsrc->reg) {
        freeRegister(sRsrc);
    }
    if (ssrc != src->reg) {
        freeRegister(ssrc);
    }

    return dest;
}

Type* CodeGenerator::relop(stack_data* b1Data, stack_data* b2Data, stack_data* opData) {
    Type* b1 = dynamic_cast<Type*>(b1Data);
    Type* b2 = dynamic_cast<Type*>(b2Data);
    string op = dynamic_cast<Binop*>(opData)->op;

    string reg1 = getRegisterIfMemory(b1);
    string reg2 = getRegisterIfMemory(b2);

    Type* b = new Type(BOOL);
    b->bool_exp = true;

    vector<int> true_list;
    vector<int> false_list;

    true_list.push_back(buffer->emit(relop_map.at(op) + " " + reg1 + ", " + reg2 + " "));
    false_list.push_back(buffer->emit("j "));

    if (reg1 != b1->reg) {
        freeRegister(reg1);
    }

    if (reg2 != b2->reg) {
        freeRegister(reg2);
    }

    b->true_list = true_list;
    b->false_list = false_list;

    return b;
}

Type* CodeGenerator::boolTrue() {
    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list.push_back(buffer->emit("j "));
    return b;
}

Type* CodeGenerator::boolFalse() {
    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list.push_back(buffer->emit("j "));
    return b;
}

Type* CodeGenerator::boolAnd(stack_data* b1Data, stack_data* b2Data, stack_data* labelData) {
    Type* b1 = dynamic_cast<Type*>(b1Data);
    Type* b2 = dynamic_cast<Type*>(b2Data);
    string label = dynamic_cast<Label*>(labelData)->label;
    buffer->bpatch(b1->true_list, label);

    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list = b2->true_list;
    b->false_list = buffer->merge(b1->false_list, b2->false_list);

    return b;
}

Type* CodeGenerator::boolOr(stack_data* b1Data, stack_data* b2Data, stack_data* labelData) {
    Type* b1 = dynamic_cast<Type*>(b1Data);
    Type* b2 = dynamic_cast<Type*>(b2Data);
    string label = dynamic_cast<Label*>(labelData)->label;
    buffer->bpatch(b1->false_list, label);

    Type* b = new Type(BOOL);
    b->bool_exp = true;
    b->true_list = buffer->merge(b1->true_list, b2->true_list);
    b->false_list = b2->false_list;

    return b;
}

Type* CodeGenerator::boolNot(stack_data* bData) {
    Type* b = new Type(BOOL);

    Type* b1 = dynamic_cast<Type*>(bData);

    b->bool_exp = true;
    b->false_list = b1->true_list;
    b->true_list = b1->false_list;

    return b;
}

string CodeGenerator::getFreeRegister() {
    if (free_registers.empty()) {
        //do something
    }
    string free_reg = free_registers.front();
    free_registers.pop_front();
    return free_reg;
}

void CodeGenerator::freeRegister(const string &name) {
    free_registers.push_front(name);
}

bool CodeGenerator::isFromMemory(const string &name) {
    return name.size() > 1
            && name.at(1) != 's'
            && name.at(1) != 't'
            && name != "$fp"
            && name != "$ra"
            && !utils.isNumber(name);
}

string CodeGenerator::getRegisterIfMemory(Type *t) {
    if (isFromMemory(t->reg)) {
        string reg = getFreeRegister();
        lw(reg, t->reg);
        return reg;
    }
    return t->reg;
}

Type* CodeGenerator::assignRegisterToID(stack_data *idData) {
    Id *id = dynamic_cast<Id *>(idData);
    pair<int, int> p = parser->getVariable(id);
    if (p.first != -1) {
        id->type.type = p.first;
        // Align offset to 4 bytes
        int offset = 4 * p.second;
        id->type.reg = utils.intToString(offset) + "($fp)";
    }

    return new Type(parser->getVariableType(idData), id->type.reg);
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
    Type *expType = dynamic_cast<Type *>(expTypeData);
    assignRegisterToID(idData);
    Id *id = dynamic_cast<Id*>(idData);
    string dest = id->type.reg;
    if (type != BOOL) {
        mov(dest, expType->reg);
    } else {
        boolAssignment(dest, expType);
    }
}

Type* CodeGenerator::newString(const string &val) {
    // Add string to data section
    string label = "str" + utils.intToString(str_count);
    buffer->emitData(label + ": .asciiz " + val);

    string reg = getFreeRegister();
    buffer->emit("la " + reg + ", " + label);

    str_count++;
    return new Type(STRING, reg);
}

void CodeGenerator::doReturn(stack_data *retExp) {
    Type * retType = dynamic_cast<Type*>(retExp);
    parser->verifyReturn(retType->type);
    mov("$v0", retType->reg);
}

void CodeGenerator::emitZeroDivisionCheck(const string& src) {
    string counter = utils.intToString(zdiv_check_counter);
    string dbzLabel = "dbz" + counter;
    string ndbzLabel = "ndbz" + counter;

    buffer->emit("beq " + src + " 0 " + dbzLabel);
    buffer->emit("j " + ndbzLabel);

    buffer->emit(dbzLabel + ":");
    li("$v0", 4);
    buffer->emit("la $a0, msg");
    buffer->emit("syscall");
    buffer->emit("j halt");

    buffer->emit(ndbzLabel + ":");
    zdiv_check_counter++;
}

void CodeGenerator::emitMain() {
    buffer->emit("main:");
    buffer->emit("move $fp, $sp");
    function_call(START_FUN, new ArgumentList()); // TODO Function call
    buffer->emit("halt:");
    buffer->emit("li $v0, 10");
    buffer->emit("syscall");
    buffer->emit(".end main");
    buffer->emitData("msg: .asciiz  \"Error division by zero\\n\"");
}
