//
// Created by Miki Mints on 2019-06-17.
//

#include "MipsWrapper.h"

MipsWrapper::MipsWrapper(CodeBuffer* buffer) :
    buffer(buffer),
    utils()
    {}


void MipsWrapper::lw(string reg /*dest*/, string src) {
    string s = "lw " + reg + ", " + src;
    buffer->emit(s);
}

void MipsWrapper::sw(string reg, string dest) {
    string s = "sw " + reg + ", " + dest;
    buffer->emit(s);
}

void MipsWrapper::li(string dest, int num) {
    string s = "li " + dest + ", " + utils.intToString(num);
    buffer->emit(s);
}

void MipsWrapper::li(string dest, string num) {
    string s = "li " + dest + ", " + num;
    buffer->emit(s);
}
