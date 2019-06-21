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

class Label : public stack_data{
public:
    string label;
    explicit Label(string label) : label(label){}
};

class Binop : public stack_data{
public:
    string op;
    Binop(const string& op) : op(op) {}
};

class while_start : public stack_data{
public:
    vector<stack_data*> v;
};

class Num : public stack_data{
public:
    int val;
    explicit Num(int val) : val(val){}
};

class Type : public stack_data {
public:
    bool bool_exp;
    int type;
    string reg;
    vector<int> true_list;
    vector<int> false_list;
    vector<int> exit_list;

    explicit Type(int type) : type(type), reg(), bool_exp(false) {}
    Type(int type, string reg) : type(type), reg(reg), bool_exp(false){}
    Type(Type& t) : type(t.type), reg(t.reg), bool_exp(false){}
    Type() : type(0), reg(""), bool_exp(false) {}

};

class Id : public stack_data {
public:
    Type type;
    string id;
    explicit Id(const string &id) : id(id) {}
    Id(const string& id, int type):
            id(id),
            type(type) {}
};

class Argument: public stack_data {
public:
    string id;
    int type;

    Argument(const string& id, int type): id(id), type(type) {}
};

class ArgumentList : public stack_data {
public:
    vector<Argument*> params;
    ArgumentList() : params(){}
    explicit ArgumentList(const vector<Argument*>& vector) : params(vector){}
};

class Preconditions : public stack_data{
public:
    int preconditions_num;
    explicit Preconditions(int num) : preconditions_num(num){}
};



#define YYSTYPE stack_data*


#endif //COMPI3_SOURCE_HPP
