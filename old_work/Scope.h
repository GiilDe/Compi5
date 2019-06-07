#ifndef UNIT_TESTS_SCOPE_H
#define UNIT_TESTS_SCOPE_H
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "output.hpp"
#include "Entry.h"
#include <algorithm>



class Scope
{
    vector<Entry*>* table;
public:
    Scope()
    {
        this->table = new vector<Entry*>();
    }

    ~Scope()
    {
        vector<Entry*>::iterator it = this->table->end();
        vector<Entry*>::iterator temp;
        --it;
        while(it != this->table->begin()){
            temp = it;
            --it;
            delete *temp;
        }
        delete(this->table);
    }

    void addEntry(string id, string type, int offset)
    {
        if(type == "STRUCT"){
            this->table->push_back(new Struct(id));
        }
        else {
            this->table->push_back(new Entry(id,type,offset));
        }
    }

    void addFunction(string id, string type, int offset){

        this->table->push_back(new Function(id,type));
    }

    void addVarsToStruct(vector<string> types, vector<string> names){
        Struct* temp = dynamic_cast<Struct*>(this->table->back());
        temp->addVars(types,names);
    }

    void addArgsToFunction(vector<string> types){
        Function* temp = dynamic_cast<Function*>(this->table->back());
        temp->addArgs(types);
    }

    void editEntriesType(){
        vector<Entry*>::iterator it = this->table->begin();
        while(it != this->table->end()){
            if((*it)->type != "STRUCT"){
                Function* temp = dynamic_cast<Function*>(*it);
                if(temp != NULL) {
                    string ret = output::makeFunctionType(temp->type, *temp->arg_types);
                    temp->editType(ret);
                }
            }
            it++;
        }
    }

    string getLastEntryType()
    {
        return  this->table->back()->type;
    }

    bool isInTable(string id)
    {
        vector<Entry*>::iterator it = this->table->begin();
        while(it != this->table->end())
        {
            if((*it)->id == id)
                return true;
            it++;
        }
        return false;
    }

    Entry* getEntry(string id)
    {
        vector<Entry*>::iterator it = this->table->begin();
        while(it != this->table->end())
        {
            if((*it)->id == id)
                return (*it);
            it++;
        }
        return NULL;
    }

    int getStructSize(string id){
        vector<Entry*>::iterator it = this->table->begin();
        while(it != this->table->end()) {
            if (((*it)->id == id) && ((*it)->type == "STRUCT")){
                Struct* temp = dynamic_cast<Struct*>(*it);
                return temp->num_of_types;
            }
            it++;
        }
        return -1;
    }

    void reveseScopeEntries(){
        reverse(this->table->begin(),this->table->end());
    }

    void printScope()
    {
        vector<Entry*>::iterator it = this->table->begin();
        vector<Entry*>* structs = new vector<Entry*>();
        while(it != this->table->end())
        {

            if((*it)->type != "STRUCT"){
                output::printID((*it)->id,(*it)->offset,(*it)->type);
            }
            else{
                structs->push_back(*it);
            }
            it++;
        }

        it = structs->begin();
        while(it != structs->end()){
            Struct* temp = dynamic_cast<Struct*>(*it);
            output::printStructType(temp->id,*temp->mem_types,*temp->mem_names);
            it++;
        }
    }
};

#endif //UNIT_TESTS_SCOPE_H
