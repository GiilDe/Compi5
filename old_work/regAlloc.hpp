#ifndef COMPI5_REGUTIL_HPP
#define COMPI5_REGUTIL_HPP

#include <iostream>

#define MIN_REG 8
#define Max_REG 25
#define REG_NUM 18
#define sp 29
#define fp 30
#define ra 31
#define v0 2

class regAlloc
{
private:
    bool allocatedRegisters[18];

public:
    regAlloc()
    {
        for(int i = 0; i < 18; i++)
        {
            allocatedRegisters[i] = false;
        }
    }

    int allocateReg()
    {
        for(int i=0; i<18; i++)
        {
            if(!this->allocatedRegisters[i])
            {
                this->allocatedRegisters[i] = true;
                return i+8;
            }
        }
        std::cout << "no regs to alloc" << std::endl;
        return -1;
    }

    void freeReg(int reg)
    {
        if(reg < MIN_REG || reg > Max_REG)
            return;
        this->allocatedRegisters[reg-8] = false;
    }

    bool isRegAllocated(int reg)
    {
        return allocatedRegisters[reg-MIN_REG];
    }
};

#endif //COMPI5_REGUTIL_HPP
