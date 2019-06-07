#ifndef UNTITLED3_SYMBOLTABLE_HPP
#define UNTITLED3_SYMBOLTABLE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "output.hpp"
#include "Scope.h"
#include "parser.hpp"
#include "utilFuncs.hpp"

using namespace std;

class SymbolTable {
private:
    vector<Scope *> *scopeTable;
    vector<int> *offset_stack;
    int loop_count;
public:
    SymbolTable() {
        this->scopeTable = new vector<Scope *>();
        this->scopeTable->push_back(new Scope());
        this->offset_stack = new vector<int>();
        this->offset_stack->push_back(0);
        loop_count = 0;
        vector<string> *temp = new vector<string>();
        temp->push_back("STRING");
        //string ret = output::makeFunctionType("VOID", *temp);
        addFunction("print", "VOID", 0);
        this->scopeTable->front()->addArgsToFunction(*temp);
        temp->pop_back();
        temp->push_back("INT");
        //ret = output::makeFunctionType("VOID", *temp);
        addFunction("printi", "VOID", 0);
        this->scopeTable->front()->addArgsToFunction(*temp);
        delete temp;
    }

    ~SymbolTable() {
        delete (this->scopeTable);
        delete (this->offset_stack);
    }

    void newScope() {
        this->scopeTable->push_back(new Scope());
        int temp = this->offset_stack->back();
        this->offset_stack->push_back(temp);
    }

    bool addEntry(string id, string type, int type_size) {
        if (this->isInTable(id)) //checks if such Entry already exists
        {
            return false;
        }

        this->scopeTable->back()->addEntry(id, type, this->offset_stack->back());
        int new_offset = this->offset_stack->back() + type_size;
        this->offset_stack->pop_back();
        this->offset_stack->push_back(new_offset);

        return true;
    }

    bool addFunction(string id, string type, int type_size) {
        if (this->isInTable(id)) //checks if such Entry already exists
        {
            return false;
        }

        this->scopeTable->back()->addFunction(id, type, this->offset_stack->back());
        int new_offset = this->offset_stack->back() + type_size;
        this->offset_stack->pop_back();
        this->offset_stack->push_back(new_offset);

        return true;
    }

    void addVarsToStruct(vector<MemStruct *> *vars) {
        vector<string> *types = new vector<string>();
        vector<string> *names = new vector<string>();
        reverse(vars->begin(),vars->end());
        std::vector<MemStruct *>::iterator it = vars->begin();
        while (it != vars->end()) {
            types->insert(types->begin(), typeToString((*it)->type));
            names->insert(names->begin(), (*(*it)->id));
            it++;
        }

        this->scopeTable->back()->addVarsToStruct(*types, *names);
        delete types;
        delete names;
    }

    void addFunctionArgsToScope(vector<FormalDec*>* args){
        std::vector<FormalDec *>::reverse_iterator it = args->rbegin();
        string type;
        while (it != args->rend()) {
            type = typeToString((*it)->type);
            if(type != "STRUCT") {
                resetStack(this->offset_stack->back() - 1);
                addEntry(*(*it)->id, type, 0);

            }
            else {
                resetStack(this->offset_stack->back() - getStructSize(*(*it)->struct_type));
                addEntry(*(*it)->id, "struct " + *(*it)->struct_type, 0);
            }
            //this->scopeTable->back()->reveseScopeEntries();
            it++;
        }
        resetStack(0);
    }

    void addArgsToFunction(vector<FormalDec*>* args) {
        {
            vector<string> *types = new vector<string>();
            std::vector<FormalDec *>::iterator it = args->begin();
            string type;
            while (it != args->end()) {
                type = typeToString((*it)->type);
                if(type != "STRUCT") {
                    types->insert(types->begin(), type);
                }
                else {
                    types->insert(types->begin(), "struct " + *(*it)->struct_type);

                }
                it++;
            }
            this->scopeTable->back()->addArgsToFunction(*types);

            delete types;
        }
    }

    void closeScope() {
        //output::endScope();
        //this->scopeTable->back()->printScope();
        this->scopeTable->pop_back();
        this->offset_stack->pop_back();
    }

    bool isInTable(string id) {
        std::vector<Scope *>::iterator it = this->scopeTable->end();
        while (it != this->scopeTable->begin()) {
            it--;
            if ((*it)->isInTable(id)) {
                return true;
            }
        }
        return false;
    }

    Entry* getEntry(string id) {
        std::vector<Scope *>::iterator it = this->scopeTable->end();
        while (it != this->scopeTable->begin()) {
            it--;
            if ((*it)->isInTable(id)) {
                return (*it)->getEntry(id);
            }
        }
        return NULL;
    }

    string getIdType(string id, int lineno)
    {
        Entry* e = getEntry(id);
        if(e == NULL)
        {
            output::errorUndef(lineno,id);
            exit(0);
        }
        return e->type;
    }

    int getStructSize(string id) {
        std::vector<Scope *>::iterator it = this->scopeTable->begin();
        if ((*it)->isInTable(id)) {
            return (*it)->getStructSize(id);
        }

        return -1;
    }

    int getStatmentStructSize(string id) {
        std::vector<Scope *>::iterator it = this->scopeTable->end();
        while (it != this->scopeTable->begin())
        {
            it--;
            if ((*it)->isInTable(id))
                return (*it)->getStructSize(id);
        }
        return -1;
    }

    Function* getFunction(string id, int lineno)
    {
        Entry* e = this->scopeTable->front()->getEntry(id);
        if(e == NULL)
        {
            output::errorUndefFunc(lineno,id);
            exit(0);
        }
        Function* f = dynamic_cast<Function*>(e);
        if(f == NULL)
        {
            output::errorUndefFunc(lineno,id);
            exit(0);
        }
        return f;
    }

    bool checkRetVal(string type)
    {
        Scope* s = this->scopeTable->front();
        if(type == s->getLastEntryType())
            return true;
        return (s->getLastEntryType() == "INT" && type == "BYTE");
    }

    int getEntryOffset(string id)
    {
        Entry* ent = getEntry(id);
        return ent->offset;
    }

    int getStructMemberOffset(string struct_id, string id)
    {
        Entry* temp = getEntry(struct_id);
        Struct* strct = dynamic_cast<Struct*>(temp);
        return strct->getFieldOffset(id);
    }

    string getStructNameByVar(string id)
    {
        Entry* e = getEntry(id);
        string struct_id = e->type;
        struct_id.replace(0,7,"");
        return struct_id;
    }



    string checkStructField(string id, string field, int lineno)
    {
        Entry* e = getEntry(id);
        if(e == NULL)
        {
            output::errorUndef(lineno,id);
            exit(0);
        }
        if(e->type.find("struct",0) == string::npos)
        {
            output::errorUndefStruct(lineno,id);
            exit(0);
        }

        string struct_id = e->type;
        struct_id.replace(0,7,"");
        e = getEntry(struct_id);
        Struct* s = dynamic_cast<Struct*>(e);
        if(s == NULL)
        {
            output::errorUndef(lineno,struct_id);
            exit(0);
        }
        string type = s->getFieldType(field);
        if(type == "")
        {
            output::errorUndefStructMember(lineno,id);
            exit(0);
        }
        return type;
    }

    bool isStructDefined(string id)
    {
        return !((getEntry(id) == NULL) || (getEntry(id)->type != "STRUCT"));
    }

    bool findMainFunction()
    {
        Entry* e = this->scopeTable->front()->getEntry("main");
        Function* f = dynamic_cast<Function*>(e);
        return !(f == NULL || f->type != "VOID" || f->arg_types->size() != 0);
    }

    void resetStack(int x) {
        this->offset_stack->pop_back();
        this->offset_stack->push_back(x);
    }

    void enteredLoop() {
        this->loop_count++;
    }

    void exitLoop() {
        this->loop_count--;
    }

    bool isInLoop() {
        return loop_count > 0;
    }

    void printTable() {
        //this->scopeTable->back()->editEntriesType();
        //output::endScope();
        //this->scopeTable->back()->printScope();
    }
};


#endif //UNTITLED3_SYMBOLTABLE_HPP
