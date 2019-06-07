#ifndef COMPI5_CODEGENERATOR_HPP
#define COMPI5_CODEGENERATOR_HPP

#include "bp.hpp"
#include "regAlloc.hpp"
#include <string>
#include <vector>
#include "output.hpp"
#include "parser.hpp"
#include "utilFuncs.hpp"
#include "symbolTable.hpp"
#include <sstream>


using namespace std;

class codeGenerator
{
private:
    CodeBuffer& cb;
    vector<regAlloc> regs;
    int str_counter;
    int div_counter;
public:
    codeGenerator():cb(CodeBuffer::instance())
    {
        regs.push_back(regAlloc());
        str_counter = 0;
        div_counter = 0;
    }

    void bpatch(const std::vector<int>& address_list, const std::string &loc)
    {
        cb.bpatch(address_list,loc);
    }

    void printCodeBuffer()
    {
        cb.printCodeBuffer();
    }

    void printDataBuffer()
    {
        cb.printDataBuffer();
    }

    int emit(const std::string &command)
    {
        return cb.emit(command);
    }

    std::string genLabel()
    {
        return cb.genLabel();
    }

    int stringToInt(string str)
    {
        stringstream ss;
        ss << str;
        int i;
        ss >> i;
        return i;
    }
    string intToStr(int num)
    {
        stringstream ss;

        ss << num;

        return ss.str();
    }

    string regToSring(int reg)
    {
        return "$" + intToStr(reg);
    }

    void stringToData(string str, int reg)
    {
        cb.emitData("msg" + intToStr(str_counter) + ": " + ".asciiz  " + str);
        cb.emit("la " + regToSring(reg) + " msg" + intToStr(str_counter));
        str_counter++;
    }


    void li(int reg, int imm)
    {
        string command = "li " + regToSring(reg) + " " + intToStr(imm);
        cb.emit(command);
    }

    void lw(int reg, int offset)
    {
        string command = "lw " + regToSring(reg) + " " + intToStr(offset) + "($fp)";
        cb.emit(command);
    }

    void sw(int reg, int offset)
    {
        string command = "sw " + regToSring(reg) + " " +intToStr(offset) + "($fp)";
        cb.emit(command);
    }

    void derefrance(int reg)
    {
        string command = "lw " + regToSring(reg) + " (" + regToSring(reg) + ")";
        cb.emit(command);
    }

    void add(int destR, int srcR)
    {
        string command = "addu " + regToSring(destR) + " " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
        freeReg(srcR);
    }

    void addNoFree(int destR, int srcR)
    {
        string command = "addu " + regToSring(destR) + " " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
    }

    void addI(int destR, int imm)
    {
        string command = "addu " + regToSring(destR) + " " + regToSring(destR) + " " + intToStr(imm);
        cb.emit(command);
    }

    void sub(int destR, int srcR)
    {
        string command = "subu " + regToSring(destR) + " " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
        freeReg(srcR);
    }

    void subNoFree(int destR, int srcR)
    {
        string command = "subu " + regToSring(destR) + " " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
    }

    void subI(int destR, int imm)
    {
        string command = "subu " + regToSring(destR) + " " + regToSring(destR) + " " + intToStr(imm);
        cb.emit(command);
    }

    void mul(int destR, int srcR)
    {
        string command = "mul " + regToSring(destR) + " " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
        freeReg(srcR);
    }

    void div(int destR, int srcR)
    {
        string command = "divu " + regToSring(destR) + " " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
        freeReg(srcR);
    }

    void move(int destR, int srcR)
    {
        string command = "move " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
        freeReg(srcR);
    }

    void moveNoFree(int destR, int srcR)
    {
        string command = "move " + regToSring(destR) + " " + regToSring(srcR);
        cb.emit(command);
    }

    void push(int reg)
    {
        subI(sp,4);
        string command = "sw " + regToSring(reg) + " " +"0($sp)";
        cb.emit(command);
    }

    void pop(int reg)
    {
        string command = "lw " + regToSring(reg) + " " +"0($sp)";
        cb.emit(command);
        addI(sp,4);
    }

    void jal(string label)
    {
        string command = "jal " + label;
        cb.emit(command);
    }

    void saveToData(string data)
    {
        cb.emitData(data);
    }

    void saveAllocatedRegs()
    {
        //cb.emit("saveRegs"); //###
        for(int i = MIN_REG; i <= Max_REG; i++)
        {
            if(regs.back().isRegAllocated(i))
                push(i);
        }
    }

    int allocateParametersInStack(vector<ExpClass*>* parameters, SymbolTable* sym)
    {
        //cb.emit("saveParameters"); //###
        vector<ExpClass*>::iterator it = parameters->begin();
        int total_size = 0;
        int size_parmeter;
        while(it != parameters->end())
        {
            size_parmeter = 4;
            if((*it)->exp_type == STRUCT_ID_TYPE)
            {
                size_parmeter = structsDefAssignment(sym->getStructNameByVar(*((*it)->structVarName)),*((*it)->structVarName), (*it)->reg,sym);
            }
            else
            {
                push((*it)->reg);
            }
            it++;
            total_size += size_parmeter;
        }
        return total_size;
    }

    void restoreAllocatedRegs()
    {
        //cb.emit("restoreRegs"); //###
        for(int i = Max_REG; i >= MIN_REG; i--)
        {
            if(regs.back().isRegAllocated(i))
                pop(i);
        }
    }

    void addPrints()
    {
        cb.emit("printi:");
        push(ra);
        move(fp,sp);
        cb.emit("lw $a0,8($sp)");
        cb.emit("li $v0,1");
        cb.emit("syscall");
        calle();

        cb.emit("print:");
        push(ra);
        move(fp,sp);
        cb.emit("lw $a0,8($sp)");
        cb.emit("li $v0,4");
        cb.emit("syscall");
        calle();
    }

    //caller saves everything in stack
    int SAVEALL(vector<ExpClass*>* parameters, SymbolTable* sym)
    {
        //emit("---save regs---");
        saveAllocatedRegs();
        //emit("---save args---");
        int size_param = allocateParametersInStack(parameters, sym);
        //emit("---save fp---");
        push(fp);
        return size_param;
    }

    //caller restores from stack
    //size_parm is the return value from SAVEALL
    void RESTOREALL(int size_parm)
    {
        //cb.emit("restoreAll"); //###
        //$ra was popped by jr
        pop(fp);
        addI(sp,size_parm);
        restoreAllocatedRegs();
    }

    int caller(string label, vector<ExpClass*>* parameters, SymbolTable* sym)
    {
        int size_parm = SAVEALL(parameters,sym);
        regs.push_back(regAlloc());
        jal(label);
        regs.pop_back();
        RESTOREALL(size_parm);
        return v0;
    }

    void calle()
    {
        //cb.emit("calle"); //###
        move(sp,fp);
        pop(ra);
        string command = "jr $ra";
        cb.emit(command);
    }

    int allocateReg()
    {
        return regs.back().allocateReg();
    }

    void freeReg(int reg)
    {
        regs.back().freeReg(reg);
    }

    void freeListReg(vector<ExpClass*>* ls)
    {
        vector<ExpClass*>::iterator it = ls->begin();
        while(it != ls->end())
        {
            freeReg((*it)->reg);
            it++;
        }
    }

    int newExpReg(int val)
    {
        int reg = regs.back().allocateReg();
        li(reg, val);
        return reg;
    }

    void calc(int x, int y, const char* op)
    {
        char temp = op[0];
        switch(temp)
        {
            case '*': mul(x, y);
                break;
            case '/': checkDevisionByZero(y); div(x, y);
                break;
            case '+': add(x, y);
                break;
            case '-': sub(x, y);
                break;
        }
        freeReg(y);
    }

    void relop(ExpClass* res, ExpClass* e1, ExpClass* e2, string op)
    {
        string jump = "";
        if(op == "<")
        {
            jump = "blt ";
        }

        if(op == "<=")
        {
            jump = "ble ";
        }

        if(op == ">")
        {
            jump = "bgt ";
        }

        if(op == ">=")
        {
            jump = "bge ";
        }

        if(op == "==")
        {
            jump = "beq ";
        }

        if(op == "!=")
        {
            jump = "bne ";
        }

        jump += regToSring(e1->reg) + " " + regToSring(e2->reg) + " ";
        vector<int>* Tlist = new vector<int>();
        vector<int>* Flist = new vector<int>();
        vector<int> temp;
        temp.push_back(cb.emit(jump));
        string f = genLabel();
        Flist->push_back(cb.emit("j "));
        string t = genLabel();
        Tlist->push_back(cb.emit("j "));
        cb.bpatch(temp,t);
        res->Tlist = Tlist;
        res->Flist = Flist;

        freeReg(e1->reg);
        freeReg(e2->reg);
    }

    void OR(ExpClass* res, ExpClass* e1, ExpClass* e2)
    {
        e1->Tlist->insert(e1->Tlist->end(), e2->Tlist->begin(), e2->Tlist->end());
        res->Tlist = e1->Tlist;
        res->Flist = e2->Flist;
    }

    void AND(ExpClass* res, ExpClass* e1, ExpClass* e2)
    {
        e1->Flist->insert(e1->Flist->end(), e2->Flist->begin(), e2->Flist->end());
        res->Tlist = e2->Tlist;
        res->Flist = e1->Flist;
    }

    void fixByteVal(int reg)
    {
        cb.emit("and " + regToSring(reg) + " " + regToSring(reg) + " 0xff");
    }

    ExpClass binopExp(ExpClass& e1, ExpClass& e2, const char* op, int line)
    {

        if(!(typeCheck(e1.exp_type, e2.exp_type) && typeCheck(e1.exp_type, INT_TYPE)))
        {
            output::errorMismatch(line);
            exit(0);
        }
        Type type = INT_TYPE;
        calc(e1.reg, e2.reg, op);

        if((e1.exp_type == BYTE_TYPE) && (e2.exp_type == BYTE_TYPE))
        {
            type = BYTE_TYPE;
            fixByteVal(e1.reg);
        }
        e1.exp_type = type;
        freeReg(e2.reg);
        return e1;
    }

    int adjustOffset(int offset)
    {
        if(offset < 0)
            offset -= 1;
        else
            offset += 1;

        return -4*offset;
    }

    int getVarOffset(string id, SymbolTable* sym)
    {
        int offset = sym->getEntryOffset(id);
        return adjustOffset(offset);
    }

    int getStructMemberOffset(string struct_var, string member, SymbolTable* sym)
    {
        int offset = sym->getEntryOffset(struct_var) + sym->getStructMemberOffset(sym->getStructNameByVar(struct_var), member);
        return adjustOffset(offset);
    }

    int getVar(string id, SymbolTable* sym)
    {
        int reg = allocateReg();
        li(reg,getVarOffset(id,sym));
        add(reg,fp);
        derefrance(reg);
        return reg;
    }

    void getBoolVar(ExpClass* e, int offset)
    {
        e->Tlist = new vector<int>();
        e->Flist = new vector<int>();
        int reg = allocateReg();
        lw(reg,offset);
        string command = "beq " + regToSring(reg) + " 1 ";
        freeReg(reg);
        e->Tlist->push_back(cb.emit(command));
        e->Flist->push_back(cb.emit("j "));
    }

    int getStructMember(string struct_var, string member, SymbolTable* sym)
    {
        int reg = allocateReg();
        li(reg,getStructMemberOffset(struct_var,member,sym));
        add(reg,fp);
        derefrance(reg);
        return reg;
    }

    void updateVarInStack(string id, int reg, SymbolTable* sym)
    {
        sw(reg, getVarOffset(id,sym));
    }

    void updateStructMemberInStack(string struct_var, string member, int reg, SymbolTable* sym)
    {
        sw(reg,getStructMemberOffset(struct_var,member,sym));
    }

    int structsDefAssignment(string struct_id, string struct_name, int reg, SymbolTable* sym)
    {
        int num_members = sym->getStatmentStructSize(struct_id);
        int pointer_reg = allocateReg();
        li(reg,getVarOffset(struct_name,sym));
        addNoFree(reg,fp);
        moveNoFree(pointer_reg,reg);
        for(int i=1; i<=num_members; i++)
        {
            derefrance(reg);
            push(reg);
            subI(pointer_reg,4);
            moveNoFree(reg,pointer_reg);
        }
        freeReg(pointer_reg);
        return num_members*4;
    }

    void structAssignment(string lval_id, string rval_id, int reg, SymbolTable* sym)
    {
        int num_members = sym->getStatmentStructSize(sym->getStructNameByVar(rval_id));
        int pointer_reg = allocateReg();
        int lval_id_offset = getVarOffset(lval_id,sym);
        int lval_id_member_offset = lval_id_offset;
        li(reg,getVarOffset(rval_id,sym));
        addNoFree(reg,fp);
        moveNoFree(pointer_reg,reg);
        for(int i=1; i<=num_members; i++)
        {
            derefrance(reg);
            sw(reg,lval_id_member_offset);
            subI(pointer_reg,4);
            moveNoFree(reg,pointer_reg);
            lval_id_member_offset += -4;
        }
        freeReg(reg);
        freeReg(pointer_reg);
    }

    void boolLiteral(ExpClass* e, int literal)
    {
        vector<int>* Tlist = new vector<int>();
        vector<int>* Flist = new vector<int>();
        if(literal)
            Tlist->push_back(cb.emit("j "));
        else
            Flist->push_back(cb.emit("j "));
        e->Tlist = Tlist;
        e->Flist = Flist;
    }

    void boolAssignment(ExpClass boolExp, string id, string member,SymbolTable* sym)
    {
        vector<int> temp;
        int reg = allocateReg();
        string Tlabel = genLabel();
        li(reg,1);
        if(member.compare("")==0)
            updateVarInStack(id,reg,sym);
        else
            updateStructMemberInStack( id,member,reg,sym);
        temp.push_back(cb.emit("j "));
        string Flabel = genLabel();
        li(reg,0);
        if(member.compare("")==0)
            updateVarInStack(id,reg,sym);
        else
            updateStructMemberInStack(id,member,reg,sym);
        string Done = genLabel();
        cb.bpatch(temp,Done);
        cb.bpatch(*(boolExp.Tlist),Tlabel);
        cb.bpatch(*(boolExp.Flist),Flabel);
        freeReg(reg);
    }

    void boolReturn(ExpClass boolExp)
    {
        vector<int> temp;
        string Tlabel = genLabel();
        li(v0,1);
        temp.push_back(cb.emit("j "));
        string Flabel = genLabel();
        li(v0,0);
        string Done = genLabel();
        cb.bpatch(temp,Done);
        cb.bpatch(*(boolExp.Tlist),Tlabel);
        cb.bpatch(*(boolExp.Flist),Flabel);
    }

    void boolCallToExp(ExpClass* e)
    {
        vector<int>* Tlist = new vector<int>();
        vector<int>* Flist = new vector<int>();
        Tlist->push_back(cb.emit("beq $v0 1 "));
        Flist->push_back(cb.emit("j "));
        e->Tlist = Tlist;
        e->Flist = Flist;
    }

    void boolExpToVal(ExpClass* e)
    {
        string Tlabel = genLabel();
    }

    void addMyMain(SymbolTable* sym)
    {
        vector<ExpClass*> temp;
        cb.emit("main:");
        caller("my_main",&temp,sym);
        cb.emit("halt:");
        cb.emit("li $v0, 10");
        cb.emit("syscall");
        cb.emit(".end main");
        cb.emitData("msg: .asciiz  \"Error division by zero\\n\"");
    }

    void checkDevisionByZero(int x)
    {
        cb.emit("beq " + regToSring(x) + " 0 dbz" + intToStr(div_counter));
        cb.emit("j ndbz" + intToStr(div_counter));
        cb.emit("dbz" + intToStr(div_counter) + ":");
        cb.emit("li $v0, 4");
        cb.emit("la $a0, msg");
        cb.emit("syscall");
        cb.emit("j halt");
        cb.emit("ndbz" + intToStr(div_counter) + ":");
        div_counter++;
    }

};

#endif //COMPI5_CODEGENERATOR_HPP
