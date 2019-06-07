#ifndef UNIT_TESTS_ENTRY_H
#define UNIT_TESTS_ENTRY_H
#include <string>
#include <vector>
#include <iostream>
#include "output.hpp"

using namespace std;
class Entry
{
public:
    string id;
    string type;
	int val;
    int offset;

    Entry(): id(""),type(""),offset(0){}
    Entry(string id, string type) : id(id),type(type),offset(0){}
    Entry(string id, string type, int offset)
    {
        this->id = id;
        this->type = type;
        this->offset = offset;
    }

    virtual ~Entry(){}

    void editType(string type){
        this->type = type;
    }
};

class Struct : public Entry{
public:
    vector<string>* mem_types;
    vector<string>* mem_names;
    int num_of_types;
    Struct(string id) : Entry(id,"STRUCT"){
        mem_types = new vector<string>();
        mem_names = new vector<string>();
        num_of_types=0;
    }
    ~Struct(){
        delete mem_names;
        delete mem_types;
    }

    void addVars(vector<string> types, vector<string> names){
        std::vector<string>::iterator it_t = types.begin();
        std::vector<string>::iterator it_n = names.begin();
        while(it_t != types.end()){
            mem_types->push_back(*it_t);
            mem_names->push_back((*it_n));
            it_n++;
            it_t++;
            num_of_types++;
        }
    }

    string getFieldType(string id)
    {
        vector<string>::iterator types = this->mem_types->begin();
        vector<string>::iterator names = this->mem_names->begin();

        while(names != this->mem_names->end())
        {
            if((*names) == id)
                return (*types);
            types++;
            names++;
        }
        return "";
    }

    int getFieldOffset(string id){
        vector<string>::iterator names = this->mem_names->begin();
        int count=0;
        while(names != this->mem_names->end()){
            if((*names) == id)
                return count;
            names++;
            count++;
        }
        return -1;
    }
};

class Function : public Entry{
public:
    vector<string>* arg_types;
    Function(string id, string type) : Entry(id,type){
        arg_types = new vector<string>();
    }

    ~Function(){
        
        delete arg_types;
    }

    void addArgs(vector<string> types){
        std::vector<string>::iterator it_t = types.begin();
        while(it_t != types.end()){
            arg_types->push_back(string(*it_t));
            it_t++;
        }
    }

};

#endif //UNIT_TESTS_ENTRY_H
