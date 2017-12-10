%option noyywrap
%option yylineno
%{
#include "grammar.tab.h"
#include <stdio.h>
#include <stdlib.h>
extern "C" int yylex();
int yydebug;
%}

WHITESPACE [ \t]
VARIABLE [_a-z]+
VALUE [0-9]+

%%
{WHITESPACE} {}
"\n" {//printf("\n");
}
"VAR" { //printf("token ");

return VAR;}
"BEGIN" { //printf("token ");
 return T_BEGIN;}
"END" { //printf("token ");
 return END;}
"IF" { //printf("token ");
 return IF;}
"ELSE" { //printf("token ");
 return ELSE;}
"ENDIF" { //printf("token ");
 return ENDIF;}
"THEN" { //printf("token ");
 return THEN;}
"WHILE" { //printf("token ");
 return WHILE;}
"DO" { //printf("token ");
 return DO;}
"ENDWHILE" { //printf("token ");
 return ENDWHILE;}
"FOR" { //printf("token ");
 return FOR;}
"FROM" { //printf("token ");
 return FROM;}
"TO" { //printf("token ");
 return TO;}
"ENDFOR" { //printf("token ");
 return ENDFOR;}
"DOWNTO" { //printf("token ");
 return DOWNTO;}
"READ" { //printf("token ");
 return READ;}
"WRITE" { //printf("token ");
 return WRITE;}
"SKIP" { //printf("token ");
 return SKIP; }
"+" { //printf("T_ADD ");
return T_ADD; }
"-" { //printf("T_MIN ");
return T_MIN;}
"*" { //printf("T_MUL ");
return T_MUL;}
"/" { //printf("T_DIV ");
return T_DIV;}
"%" { //printf("T_MOD ");
return T_MOD;}
"=" { //printf("T_EQ ");
return T_EQ;}
"<>" { //printf("T_NEQ ");
return T_NEQ;}
"<" { //printf("T_RGT ");
return T_RGT;}
"<=" { //printf("T_RGE ");
return T_RGE;}
">=" { //printf("T_LGE ");
return T_LGE;}
">" { //printf("T_LGT ");
return T_LGT;}
":=" { //printf("T_ASG ");
return T_ASG;}
";" { //printf("T_EL ");
return T_EL;}
"[" { //printf("T_LBR ");
return T_LBR;}
"]" { //printf("T_RBR ");
return T_RBR;}
{VARIABLE} {//printf("var ");
yylval.string = strdup(yytext);
return PID;}
{VALUE} {//printf("value ");
yylval.string = strdup(yytext);
return num;}
[_a-z0-9]+						{
return ERR;}
.	{return ERR; }
%%
/*
int main (void)
{

yydebug = 1;
yylex();

return 0;
}*/
