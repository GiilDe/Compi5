//
// Created by Miki Mints on 2019-06-17.
//

#include "MipsWrapper.h"

MipsWrapper::MipsWrapper(Parser* parser) :
        buffer(&CodeBuffer::instance()),
        parser(parser),
        utils() {

    for (int i = 0; i <= 7; ++i) {
        string num = utils.intToString(i);
        free_registers.push_front("$t" + num);
        free_registers.push_front("$s" + num);
    }
    free_registers.push_front("$t8");
    free_registers.push_front("$t9");
}


void MipsWrapper::lw(const string &reg /*dest*/, const string &src) {
    string s = "lw " + reg + ", " + src;
    buffer->emit(s);
}

void MipsWrapper::sw(const string &reg, const string &dest) {
    string s = "sw " + reg + ", " + dest;
    buffer->emit(s);
}

void MipsWrapper::li(const string &dest, int num) {
    string s = "li " + dest + ", " + utils.intToString(num);
    buffer->emit(s);
}

void MipsWrapper::li(const string &dest, const string &num) {
    string s = "li " + dest + ", " + num;
    buffer->emit(s);
}

void MipsWrapper::push(const string &dest) {
    buffer->emit("subi $sp, 4");
    buffer->emit("sw " + dest + ", " + " 0($sp)");
}

void MipsWrapper::pop(const string& dest) {
    buffer->emit("lw " + dest + ", " +"0($sp)");
    buffer->emit("addi $sp, 4");
}

void MipsWrapper::mov(const string &dest, const string &src) {
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

void MipsWrapper::binop(Type *dest, Type *Rsrc, Type *src, string op) {
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

    if (op == "+") {
        op = "add";
    } else if (op == "-") {
        op = "sub";
    } else if (op == "*") {
        op = "mul";
    } else {
        op = "div";
    }

    string s = op + " " + sdest + ", " + sRsrc + ", " + ssrc;
    buffer->emit(s);
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
}

string MipsWrapper::getFreeRegister() {
    if (free_registers.empty()) {
        //do something
    }
    string free_reg = free_registers.front();
    free_registers.pop_front();
    return free_reg;
}

void MipsWrapper::freeRegister(const string &name) {
    free_registers.push_front(name);
}

bool MipsWrapper::isFromMemory(const string &name) {
    return name.size() > 1
           && name.at(1) != 's'
           && name.at(1) != 't'
           && !utils.isNumber(name);
}

string MipsWrapper::getRegisterIfMemory(Type *t) {
    if (isFromMemory(t->reg)) {
        string reg = getFreeRegister();
        lw(reg, t->reg);
        return reg;
    }
    return t->reg;
}

void MipsWrapper::assignRegisterToID(stack_data *idData) {
    Id *id = dynamic_cast<Id *>(idData);
    pair<int, int> p = parser->getVariable(id);
    if (p.first != -1) {
        id->type.type = p.first;
        int offset = p.second;
        id->type.reg = utils.intToString(offset) + "($fp)";
    }
}

void MipsWrapper::boolAssignment(const string& dest, Type *t) {
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

CodeBuffer *MipsWrapper::buf() {
    return buffer;
}

void MipsWrapper::printCodeBuffer() {
    buffer->printCodeBuffer();
}

void MipsWrapper::doAssignOp(stack_data *expTypeData, stack_data *idData, int type) {
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
