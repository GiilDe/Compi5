%{
	#include <stdio.h>
	#include <string.h>
	#include "parser.hpp"
	#include "output.hpp"
	#include "parser.tab.hpp"
%}

%option yylineno
%option noyywrap

extern int yylineno;

%%

void 							{return VOID;}
int								{return INT;}
byte							{return BYTE;}
b								{return B;}
bool							{return BOOL;}
struct							{return STRUCT;}
and								{return AND;}
or								{return OR;}
not								{return NOT;}
true							{return TRUE;}
false							{return FALSE;}
return							{return RETURN;}
if								{return IF;}
else							{return ELSE;}
while							{return WHILE;}
break							{return BREAK;}
continue						{return CONTINUE;}
;       						{return SC;}
,       						{return COMMA;}
\.       						{return PERIOD;}
\(       						{return LPAREN;}
\)       						{return RPAREN;}
\{       						{return LBRACE;}
\}       						{return RBRACE;}
=       						{return ASSIGN;}
(==|!=)							{yylval.op = (char*)malloc(strlen(yytext));strcpy(yylval.op,yytext); return EQUALITY;}
(<|>|<=|>=)						{yylval.op = (char*)malloc(strlen(yytext));strcpy(yylval.op,yytext); return RELATIONAL;}
(\+|-)							{yylval.op = (char*)malloc(strlen(yytext));strcpy(yylval.op,yytext); return ADDITIVE;}
(\*|\/)                       	{yylval.op = (char*)malloc(strlen(yytext));strcpy(yylval.op,yytext); return MULT;}
[a-zA-Z][a-zA-Z0-9]*            {yylval.str = new string(yytext); return ID;}
(0|[1-9][0-9]*)                 {yylval.val = atoi(yytext); return NUM;}
\"([^\n\r\"\\]|\\[rnt\"\\])+\"  {yylval.str = new string(yytext); return STRING;}

\/\/[^\r\n]*(\r|\n|\r\n)?		
[\t \r\n]+					
.								{output::errorLex(yylineno); exit(0);}

%%














