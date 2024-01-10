%{
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include "utils.h"
#include "expr_data.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
using namespace std;

std::vector<FunctionSymbol> functions;
std::vector<Symbol> currentParameters;

%}
%union {
    int int_val;
    float float_val;
    char char_val;
    char* string;
    bool boolean;
    ExprData* expr_data;
}
%token BGIN END ASSIGN 
%token <int_val> NR
%token <float_val> FLOAT
%token <boolean> BOOL
%token <char_val> CHAR
%token <string> STRING
%token <string> CONST ID TYPE
%token ARRAY_BRACKETS
%token F_START
%token <string> FRAME_KEYWORD OPEN_BRACE CLOSE_BRACE
%token IF WHILE FOR
%type <expr_data> number_expr bool_expr expr
%type <string> parameters parameter_declaration
%start progr

%left OR
%left AND
%left EQ NEQ
%left LT LTE GT GTE
%right '!'
%left '+' '-'
%left '*' '/'
%%
progr:  frame_definition declarations f_declarations block {
        printf("The syntax of the code is correct.\n");
        }
        ;

frame_definition : FRAME_KEYWORD ID OPEN_BRACE {
    initParameters();
    std::string frameName = std::string($2) + " (frame)";
    enterScope(frameName);
} frame_body f_declarations CLOSE_BRACE {    
    leaveScope();
}
;

frame_body  :  declarations
            |  ctrl_statements ';'
            |  declarations ctrl_statements ';'
            ;

declarations :  decl ';'          
	         |  declarations decl ';'
             ;

decl : const_decl | var_decl | array_decl;

const_decl : CONST TYPE ID { 
            Symbol* sym = table.findSymbol($3);
            if (sym != nullptr) {
                yyerror(("Variable previosly defined: " + std::string($3)).c_str());
            } 
            else {
                Symbol symbol;
                symbol.name = $3;
                symbol.type = $2;
                symbol.isConstant = true;
                symbol.scope = currentScope();
                table.addSymbol(symbol);
            }
      }
      |
      // TODO: Implement AST evaluation
      CONST TYPE ID ASSIGN expr{ 
            Symbol* sym = table.findSymbol($3);
            if (sym != nullptr) {
                yyerror(("Variable previosly defined: " + std::string($3)).c_str());
            } 
            else {
                Symbol symbol;
                symbol.name = $3;
                symbol.type = $2;
                symbol.isConstant = true;
                symbol.scope = currentScope();
                std::string value {"test value"};
                symbol.value = value;
                table.addSymbol(symbol);
            }
      }
;

var_decl : TYPE ID { 
            Symbol* sym = table.findSymbol($2);
            if (sym != nullptr) {
                yyerror(("Variable previosly defined: " + std::string($2)).c_str());
            } 
            else {
                Symbol symbol;
                symbol.name = $2;
                symbol.type = $1;
                symbol.isConstant = false;
                symbol.scope = currentScope();
                table.addSymbol(symbol);
            }
            } 
            | TYPE ID ASSIGN expr { 
                Symbol* sym = table.findSymbol($2);
                if (sym != nullptr) {
                    yyerror(("Variable previosly defined: " + std::string($2)).c_str());
                } 
                else {
                    if ($1 != $4->type) { 
                        yyerror(("asgn type missmatch. type L: " + std::string($1) + 
                        " type R: " + std::string($4)).c_str());
                    }
                    else {
                        Symbol symbol;
                        symbol.name = $2;
                        symbol.type = $1;
                        symbol.isConstant = false;
                        symbol.scope = currentScope();
                        std::string value {"test value"};
                        symbol.value = value;
                        table.addSymbol(symbol);
                    }
                }
            } 
            ;

array_decl : TYPE ID '[' NR ']' {
                Symbol* sym = table.findSymbol($2);
                if (sym != nullptr) {
                    yyerror(("Variable previosly defined: " + std::string($2)).c_str());
                } 
                else {
                    Symbol symbol;
                    symbol.name = $2;
                    std::string arrayDecl {"[]"};
                    symbol.type = $1 + arrayDecl;
                    symbol.arraySize = std::to_string($4);
                    symbol.isConstant = false;
                    symbol.scope = currentScope();
                    table.addSymbol(symbol);
                }
            }
            | 
            | TYPE ID '[' NR ']' ASSIGN expr {
                Symbol* sym = table.findSymbol($2);
                if (sym != nullptr) {
                    yyerror(("Variable previosly defined: " + std::string($2)).c_str());
                }
                else {
                    Symbol symbol;
                    symbol.name = $2;
                    std::string arrayDecl {"[]"};
                    symbol.type = $1 + arrayDecl;
                    symbol.arraySize = std::to_string($4);
                    symbol.isConstant = false;
                    symbol.scope = currentScope();
                    std::string value {"test value"};
                    symbol.value = value;
                    table.addSymbol(symbol);
                }
            }
            ;

ctrl_keywords   : IF | WHILE | FOR ;
ctrl_statements : ctrl_keywords '(' ')' OPEN_BRACE declarations CLOSE_BRACE
                | ctrl_statements ctrl_keywords '(' expr ')' OPEN_BRACE declarations CLOSE_BRACE
                ;

f_declarations :
f_declarations F_START TYPE ID {
    initParameters();
    enterScope($4);
}
'(' parameters ')' 
OPEN_BRACE declarations CLOSE_BRACE  
{
    FunctionSymbol function;
    function.returnType = $3;
    function.name = $4;     
    function.parameters = currentParameters;
    function.definedInClass = currentScope();
    table.addFunctionSymbol(function);
    leaveScope();
}
| F_START TYPE ID {
    initParameters();
    enterScope($3);
}
'(' parameters ')' OPEN_BRACE declarations CLOSE_BRACE
{
    FunctionSymbol function;
    function.returnType = $2;
    function.name = $3;
    function.parameters = currentParameters;
    function.definedInClass = currentScope();
    table.addFunctionSymbol(function);
    leaveScope();
}
;

parameters : 
| parameter_declaration
| parameters ',' parameter_declaration
;

parameter_declaration : TYPE ID {
    addParameter($1, $2);
}

block : BGIN list END  
     ;

list : statement ';' 
     | list statement ';'
     | field_access
     | list field_access
     | method_call
     | list method_call 
     | ctrl_statements ';'
     | list ctrl_statements ';'
     ;

// This is probably rendundant at this point (expr works)
statement: id_assign ID {
    Symbol* sym = table.findSymbol($2);
    if (sym == nullptr) {
        yyerror(("Variable not defined: " + std::string($2)).c_str());
    }
}
| id_assign NR
| id_assign FLOAT  	
| id_assign BOOL	 
| ID '(' call_list ')' {
    FunctionSymbol* sym = table.findFunctionSymbol($1);
    if (sym == nullptr) {
        yyerror(("Function not defined: " + std::string($1)).c_str());
    }
}
;

id_assign : ID ASSIGN {
    Symbol* sym = table.findSymbol($1);
    if (sym == nullptr) {
        yyerror(("Variable not defined: " + std::string($1)).c_str());
    }
}
;

field_access: ID '.' ID ';'{
    // This needs more work, frames should be stored diferently 
    // to acces the methods
    Symbol* sym = table.findSymbol($1);
    if (sym == nullptr) {
        yyerror(("Frame not existent: " + std::string($1)).c_str());
    }
}
;

method_call: ID '.' ID '(' call_list ')' ';' {
    // This is not good, the search should be done in the frames
    // syntax: <frame_name> . <frame_function>
    // TODO: Store frames in the table
    // The code below will produce an error, since frames are not defined
    FunctionSymbol* sym = table.findFunctionSymbol($1);
    if (sym == nullptr) {
        yyerror(("Function not defined: " + std::string($1)).c_str());
    }

}
| ID '.' ID '(' ')' ';'
;

call_list : expr
          | call_list ',' expr
          ;
%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     cout << "Variables:" << endl;
     cout << "Table:\n";
     table.printToFile("table.txt");
}