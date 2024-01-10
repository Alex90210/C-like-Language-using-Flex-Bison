%{
#include <stdio.h>
#include "limbaj.tab.h"
%}
%option noyywrap
%%
"Eval" { return EVAL; }
"TypeOf" { return TYPEOF; }
"[]" { return ARRAY_BRACKETS; }
"frame" { return FRAME_KEYWORD; }
"{" { return OPEN_BRACE; }
"}" { return CLOSE_BRACE; }
"const" {return CONST; }
"begin_progr" {return BGIN;}
"end_progr" {return END;}
"true"  { yylval.boolean = true; return BOOL; }
"false" { yylval.boolean = false; return BOOL; }
"||" { return OR; }
"&&" { return AND; }
"::" { return CHAR_ASSIGN; }
"if" { return IF; }
"def" { return F_START; }
"return" { return RETURN; }
"while" { return WHILE; }
"for" { return FOR; }
"skipControlStatements();" {return NO_CTRL;}
"int"|"float"|"char"|"string"|"bool" {yylval.string = strdup(yytext);return TYPE;}
[a-zA-Z][a-zA-Z0-9]* {yylval.string = strdup(yytext); return ID;}
":=" {return ASSIGN;}
">="  { return GE; }
"=="  { return EQ; }
"!="  { return NE; }
"<="  { return LE; }
">"   { return GT; }
"<"   { return LT; }
"'"[^']"'" {
    yylval.string = (char*)malloc(2 * sizeof(char));
    yylval.string[0] = yytext[1];
    yylval.string[1] = '\0';
    return CHAR;
}

"\"[^\"]*\"" {
    yylval.string = (char*)malloc(strlen(yytext) - 1); // Allocate space for string without quotes
    strncpy(yylval.string, yytext + 1, strlen(yytext) - 2); // Copy without quotes
    yylval.string[strlen(yytext) - 2] = '\0'; // Null terminator
    return STRING;
}
[0-9]+ {
    yylval.int_val = atoi(yytext);
    return NR;
}
[0-9]+\.[0-9]+ {
    yylval.float_val = atof(yytext);
    return FLOAT;
}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
