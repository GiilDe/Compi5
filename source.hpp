//
// Created by Gilad on 13-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class stack_data {
public:
    virtual ~stack_data(){};
};


class Binop : public stack_data{
public:
    string op;
    Binop(const string& op) : op(op) {}
};

class Num : public stack_data{
public:
    int val;
    explicit Num(int val) : val(val){}
};

class Type : public stack_data {
public:
    int type;
    string reg;
    explicit Type(int type) : type(type), reg(){}
    Type(int type, string reg) : type(type), reg(reg){}
    Type(Type& t) : type(t.type), reg(t.reg){}
    Type() : type(0), reg("") {}
};

class Id : public stack_data {
public:
    Type type;
    string id;
    explicit Id(const string &id) : id(id) {}
};

class TypesList : public stack_data {
public:
    vector<int> params;
    TypesList() : params(){}
    TypesList(vector<int> vector) : params(vector){}
};

class Preconditions : public stack_data{
public:
    int preconditions_num;
    Preconditions(int num) : preconditions_num(num){}
};

class PrecondList : public stack_data{
public:
    vector<int> preconditions_nums;
    PrecondList(int num){
        preconditions_nums.push_back(num);
    }
    PrecondList() : preconditions_nums(){}
};



#define YYSTYPE stack_data*


#endif //COMPI3_SOURCE_HPP
