#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std ;

enum Type {INT_TYPE, STRING_TYPE, BYTE_TYPE, BOOL_TYPE, STRUCT_TYPE, VOID_TYPE, STRUCT_ID_TYPE};

typedef struct
{
	Type exp_type;
	int value;
	int reg;
	string* id;
    string* structVarName;
    vector<int>* Tlist;
    vector<int>* Flist;
}ExpClass;

typedef struct
{
	Type type;
	string* struct_type;
	string* id;
}FormalDec;

typedef struct
{
	Type type;
	string* id;
}MemStruct;

typedef struct
{
	string* struct_id;
}StructType;

typedef  struct
{
    int address;
}breackContinue;

typedef struct
{
    vector<int>* Slist;
    vector<int>* Elist;
}statement;


typedef union
{
	MemStruct mem_struct;
	ExpClass exp;
	FormalDec formalDec;
	vector<ExpClass*>* exp_list;
	vector<MemStruct*>* struct_list;
	vector<FormalDec*>* formalDec_list;
	StructType struct_type;
    breackContinue jump;
    statement state;
	char* op;
    string* str;
	int val;
	
}STYPE;



/*
typedef struct
{
	string exp_type;
	int value;
}Expclass;

typedef union
{
	Expclass exp;
	const char* op;
	int val;
}STYPE;*/
#define YYSTYPE STYPE

#endif //COMPI3_SOURCE_HPP
