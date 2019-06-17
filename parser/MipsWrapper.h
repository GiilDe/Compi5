//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_MIPSWRAPPER_H
#define COMPI5_MIPSWRAPPER_H


#include <bp.hpp>
#include "Utils.h"

class MipsWrapper {

private:
    CodeBuffer* buffer;
    Utils utils;

public:
    explicit MipsWrapper(CodeBuffer* buffer);

    void lw(string reg /*dest*/, string src);

    void sw(string reg, string dest);

    void li(string dest, int num);

    void li(string dest, string num);

};


#endif //COMPI5_MIPSWRAPPER_H
