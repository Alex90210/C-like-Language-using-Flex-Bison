%{
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <variant>
#include "utils.h"
#include "AST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
SymbolTable table;
using namespace std;

std::vector<FunctionSymbol> functions;
std::vector<Symbol> currentParameters;

void initParameters() {
    currentParameters.clear();
}

void addParameter(const std::string& type, const std::string& name) {
    Symbol symbol;
    symbol.name = name;
    symbol.type = type;
    currentParameters.push_back(symbol);
}

std::string getTypeOf(const std::string& operand) {

    Symbol* sym = table.findSymbol(operand);
    if (sym != nullptr) {
        return sym->type;
    }

    if (isNumber(operand)) {
        return "int";
    }

    if (isFloat(operand)) {
        return "float";
    }

    return "unknown";
}

std::vector<std::string> splitTypes(const char* concatenatedTypes) {
    std::vector<std::string> types;
    std::istringstream iss(concatenatedTypes);
    std::string type;
    while (iss >> type) {
        types.push_back(type);
    }
    return types;
}
%}
%union {
    int int_val;
    float float_val;
    char char_val;
    char* string;
    bool boolean;
    void* node;
}
%token BGIN END ASSIGN 
%token <int_val> NR
%token <float_val> FLOAT
%token <boolean> BOOL
%token <string> CHAR
%token <string> STRING
%token <string> CONST ID TYPE
%token EVAL TYPEOF
%token ARRAY_BRACKETS
%token F_START RETURN
%token <string> FRAME_KEYWORD OPEN_BRACE CLOSE_BRACE
%token IF WHILE FOR NO_CTRL
%token CHAR_ASSIGN
%token GE EQ NE LE GT LT
%type <node> number_expr bool_expr expr
%type <string> char_expr
// %type <string> number_expr bool_expr expr
%type <string> parameters parameter_declaration call_arguments call_list
%start progr

%left OR
%left AND
%right '!'
%left EQ NE
%left '<' LE '>' GE
%left '+' '-'
%left '*' '/'
%%
progr:  frame_definition declarations f_declarations block {
        printf("The syntax of the code is correct.\n");
        }
        ;

frame_definition : FRAME_KEYWORD ID OPEN_BRACE {
    initParameters();
    table.addFrame(Frame{std::string($2)});
    std::string frameName = std::string($2) + " FRAME";
    enterScope(frameName);
} frame_body f_declarations CLOSE_BRACE {    
    leaveScope();
}
| frame_definition FRAME_KEYWORD ID OPEN_BRACE {
    initParameters();
    table.addFrame(Frame{std::string($2)});
    std::string frameName = std::string($2) + " FRAME";
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

const_decl : 
    CONST TYPE ID { 
        Symbol* sym = table.findSymbol($3);
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string($3)).c_str());
        } else {
            Symbol symbol;
            symbol.name = $3;
            symbol.type = $2;
            symbol.isConstant = true;
            symbol.scope = currentScope();

            if (endsWithFrame(currentScope())) {
                std::string frameName = extractBeforeFrame(currentScope());
                Frame* framePtr = table.findFrame(frameName);
                if (framePtr) {
                    framePtr->addSymbol(symbol);
                } else {
                    yyerror(("Frame not defined: " + frameName).c_str());
                }
            } else {
                table.addSymbol(symbol);
            }
        }
    }
    | CONST TYPE ID ASSIGN expr { 
        ASTNode* exprNode = static_cast<ASTNode*>($5);  
        double result = exprNode->evaluate(table);
        std::cout << "Value of " << std::string($3) << ": " << result << std::endl;
        Symbol* sym = table.findSymbol($3);
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string($3)).c_str());
        } else {
            if (std::string($2) != exprNode->varType) {
                yyerror(("Type mismatch in assignment. L-type:" + std::string($2) +
                " R-type:" + exprNode->varType).c_str());
            } else {
                Symbol symbol;
                symbol.name = $3;
                symbol.type = $2;
                symbol.isConstant = true;
                symbol.scope = currentScope();
                symbol.value = std::to_string(result);

                if (endsWithFrame(currentScope())) {
                    std::string frameName = extractBeforeFrame(currentScope());
                    Frame* framePtr = table.findFrame(frameName);
                    if (framePtr) {
                        framePtr->addSymbol(symbol);
                    } else {
                        yyerror(("Frame not defined: " + frameName).c_str());
                    }
                } else {
                    table.addSymbol(symbol);
                }
            }    
        }
    }
;

var_decl : 
    TYPE ID { 
        Symbol* sym = table.findSymbol($2);
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string($2)).c_str());
        } else {
            Symbol symbol;
            symbol.name = $2;
            symbol.type = $1;
            symbol.isConstant = false;
            symbol.scope = currentScope();

            if (endsWithFrame(currentScope())) {
                std::string frameName = extractBeforeFrame(currentScope());
                Frame* framePtr = table.findFrame(frameName);
                if (framePtr) {
                    framePtr->addSymbol(symbol);
                } else {
                    yyerror(("Frame not defined: " + frameName).c_str());
                }
            } else {
                table.addSymbol(symbol);
            }
        }
    }
    | TYPE ID ASSIGN expr {
        ASTNode* exprNode = static_cast<ASTNode*>($4);  
        double result = exprNode->evaluate(table);
        std::cout << "Value of " << std::string($2) << ": " << result << std::endl;
        Symbol* sym = table.findSymbol($2);
        if (sym != nullptr && currentScope() == sym->scope) {
            yyerror(("Variable previously defined: " + std::string($2)).c_str());
        } else {
            if (std::string($1) != exprNode->varType) {
                yyerror(("Type mismatch in assignment. L-type:" + std::string($1) +
                " R-type:" + exprNode->varType).c_str());
            } else {
                Symbol symbol;
                symbol.name = $2;
                symbol.type = $1;
                symbol.isConstant = false;
                symbol.scope = currentScope();
                symbol.value = std::to_string(result);

                if (endsWithFrame(currentScope())) {
                    std::string frameName = extractBeforeFrame(currentScope());
                    Frame* framePtr = table.findFrame(frameName);
                    if (framePtr) {
                        framePtr->addSymbol(symbol);
                    } else {
                        yyerror(("Frame not defined: " + frameName).c_str());
                    }
                } else {
                    table.addSymbol(symbol);
                }
            }
        }
    }
    | TYPE ID CHAR_ASSIGN char_expr {
        if ($4 == nullptr) {
            yyerror("Invalid character expression.");
        } else {
            Symbol* sym = table.findSymbol($2);
            if (sym != nullptr && currentScope() == sym->scope) {
                yyerror(("Variable already defined: " + std::string($2)).c_str());
            } else {
                Symbol symbol;
                symbol.name = $2;
                symbol.type = $1;
                symbol.isConstant = false;
                symbol.scope = currentScope();
                symbol.value = $4; // Assuming $

                if (endsWithFrame(currentScope())) {
                    std::string frameName = extractBeforeFrame(currentScope());
                    Frame* framePtr = table.findFrame(frameName);
                    if (framePtr) {
                        framePtr->addSymbol(symbol);
                    } else {
                        yyerror(("Frame not defined: " + frameName).c_str());
                    }
                } else {
                    table.addSymbol(symbol);
                }
            }
        }
    }
;

array_decl : array_decl : TYPE ID '[' NR ']' {
                Symbol* sym = table.findSymbol($2);
                if (sym != nullptr && currentScope() == sym->scope) {
                    yyerror(("Variable previously defined: " + std::string($2)).c_str());
                } 
                else {
                    Symbol symbol;
                    symbol.name = $2;
                    std::string arrayDecl {"[]"};
                    symbol.type = $1 + arrayDecl;
                    symbol.arraySize = $4;
                    symbol.isConstant = false;
                    symbol.scope = currentScope();

                    std::vector<double> stringArray(symbol.arraySize, 0);
                    symbol.values = stringArray;

                    if (endsWithFrame(currentScope())) {
                        std::string frameName = extractBeforeFrame(currentScope());

                        Frame* framePtr = table.findFrame(frameName);
                        if (framePtr) {
                            framePtr->addSymbol(symbol);
                        }
                        else {
                            yyerror(("Frame not defined: " + frameName).c_str());
                        }
                    }
                    else {
                        table.addSymbol(symbol);
                    }
                }
            }
            // String is already a vector of chars, so its not that important
            // But if you implement it, you chould ckect the type of the expression
            // and have in the symbol class a vector for each type
            // WORKS: Each vector type is assigned a vector with the values of the expr
            | TYPE ID '[' NR ']' ASSIGN expr {
                Symbol* sym = table.findSymbol($2);
                if (sym != nullptr && currentScope() == sym->scope) {
                    yyerror(("Variable previosly defined: " + std::string($2)).c_str());
                } 
                else {
                    if (endsWithFrame(currentScope())) {
                        std::string frameName = extractBeforeFrame(currentScope());
                        std::cout << "ARRAY IS IN SCOPE: "<< frameName << std::endl;

                        Symbol symbol;
                        symbol.name = $2;
                        std::string arrayDecl {"[]"};
                        symbol.type = $1 + arrayDecl;
                        symbol.arraySize = $4;
                        symbol.isConstant = false;
                        symbol.scope = currentScope();


                        ASTNode* exprNode = static_cast<ASTNode*>($7);
                        double initValue = exprNode->evaluate(table);

                        std::vector<double> stringArray(symbol.arraySize, initValue);
                        symbol.values = stringArray;

                        Frame* framePtr = table.findFrame(frameName);
                        // std::cout << "frame names: " << table.frames.size() << std::endl;
                        // the names are correctly registred before the find() function is called
                        if (framePtr) {
                            framePtr->addSymbol(symbol);
                        }
                        else {
                            yyerror(("Frame not defined: " + frameName).c_str());
                        }
                    }
                    else {
                        Symbol symbol;
                        symbol.name = $2;
                        std::string arrayDecl {"[]"};
                        symbol.type = $1 + arrayDecl;
                        symbol.arraySize = $4;
                        symbol.isConstant = false;
                        symbol.scope = currentScope();

                        ASTNode* exprNode = static_cast<ASTNode*>($7);
                        double initValue = exprNode->evaluate(table);

                        std::vector<double> stringArray(symbol.arraySize, initValue);
                        symbol.values = stringArray;

                        table.addSymbol(symbol);
                    }
                }
            }
            ;

ctrl_keywords   : IF | WHILE | FOR ;
ctrl_operators : GE | EQ | NE | LE | GT | LT;
ctrl_statements : ctrl_keywords '(' ')' OPEN_BRACE declarations CLOSE_BRACE
                | ctrl_statements ctrl_keywords '('expr')' OPEN_BRACE declarations CLOSE_BRACE
                | NO_CTRL
                ;

// --------------------- EXPR'S ---------------------

char_expr:
    CHAR {
        char *charValue = (char *)malloc(2 * sizeof(char));
        charValue[0] = $1[1];
        charValue[1] = '\0';
        printf("CHAR case: %s\n", charValue);
        $$ = charValue;
    }
    | STRING {
        printf("STRING case: %s\n", $1);
        $$ = $1;
    }
    | ID {
        Symbol* sym = table.findSymbol($1);
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string($1)).c_str());
            $$ = nullptr;
        } else {
            $$ = strdup(sym->value.c_str());
            printf("STRING case: %s\n", (char*)$$);
        }
    }
;


expr:
    number_expr {
        $$ = $1;
    }
    | bool_expr {
        $$ = $1;
    }
    ;

number_expr:
    number_expr '+' number_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>($1)->varType, "+", 
        static_cast<ASTNode*>($1), static_cast<ASTNode*>($3)));
    }
    | number_expr '-' number_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>($1)->varType, "-", 
        static_cast<ASTNode*>($1), static_cast<ASTNode*>($3)));
    }
    | number_expr '*' number_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>($1)->varType, "*", 
        static_cast<ASTNode*>($1), static_cast<ASTNode*>($3)));
    }
    | number_expr '/' number_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::OPERATOR, static_cast<ASTNode*>($1)->varType, "/", 
        static_cast<ASTNode*>($1), static_cast<ASTNode*>($3)));
    }
    | '(' number_expr ')' { $$ = $2; }
    | ID {
        Symbol* sym = table.findSymbol($1);
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string($1)).c_str());
            $$ = nullptr;
        } else {
            $$ = static_cast<void*>(new ASTNode(ASTNode::IDENTIFIER, sym->type, sym->name));
        }
    }
    | ID '.' ID {
        Frame* frame = table.findFrame($1);
        if (frame == nullptr) {
            yyerror(("Frame not defined: " + std::string($1)).c_str());
            $$ = nullptr;
        } else {
            Symbol* sym = frame->findSymbol($3);
            if (sym == nullptr) {
                yyerror(("Symbol not defined in frame '" + std::string($1) + "': " + std::string($3)).c_str());
                $$ = nullptr;
            } else {
                $$ = static_cast<void*>(new ASTNode(ASTNode::IDENTIFIER, sym->type, sym->name));
            }
        }
    }
    | ID '[' NR ']' {
        Symbol* sym = table.findSymbol($1);
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string($1)).c_str());
            $$ = nullptr;
        } else if (sym->type.find("[]") == std::string::npos) {
            yyerror(("Variable is not an array: " + std::string($1)).c_str());
            $$ = nullptr;
        } else {
            ASTNode* indexNode = new ASTNode(ASTNode::NUMBER, "int", std::to_string($3));
            $$ = static_cast<void*>(new ASTNode(ASTNode::ARRAY_ACCESS, sym->type, sym->name, nullptr, indexNode));
        }
    }
    | NR {
        $$ = static_cast<void*>(new ASTNode(ASTNode::NUMBER, "int", std::to_string($1)));
    }
    | FLOAT {
        $$ = static_cast<void*>(new ASTNode(ASTNode::NUMBER, "float", std::to_string($1)));
    }
    | number_expr GE number_expr
    | number_expr EQ number_expr
    | number_expr NE number_expr
    | number_expr LE number_expr
    | number_expr '>' number_expr
    | number_expr '<' number_expr
    ;

bool_expr:
    bool_expr OR bool_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::BOOL_OPERATOR, "bool", "OR", 
        static_cast<ASTNode*>($1), static_cast<ASTNode*>($3)));
    }
    | bool_expr AND bool_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::BOOL_OPERATOR, "bool", "AND", 
        static_cast<ASTNode*>($1), static_cast<ASTNode*>($3)));
    }
    | '!' bool_expr {
        $$ = static_cast<void*>(new ASTNode(ASTNode::BOOL_OPERATOR, "bool", "!", 
        nullptr, static_cast<ASTNode*>($2)));
    }
    | '(' bool_expr ')' {
        $$ = $2;
    }
    | BOOL {
        std::string boolValue = ($1) ? "true" : "false";
        $$ = static_cast<void*>(new ASTNode(ASTNode::BOOL_VALUE, "bool", boolValue));
    }
    ;

// --------------------- END EXPR'S ---------------------

f_declarations :
f_declarations F_START TYPE ID {
    FunctionSymbol function;
    function.returnType = $3;
    function.name = $4;     
    function.parameters = currentParameters;
    std::cout << "PARAMETERS: " << currentParameters.size() << std::endl;
    function.definedInClass = currentScope();
    
    if (endsWithFrame(currentScope())) {
        std::string frameName = extractBeforeFrame(currentScope());
        Frame* framePtr = table.findFrame(frameName);
        if (framePtr) {
            framePtr->addFunctionSymbol(function);
        } else {
            yyerror(("Frame not defined: " + frameName).c_str());
        }
    } else {
        table.addFunctionSymbol(function);
    }

    initParameters();
    enterScope($4);
}
'(' parameters ')' 
OPEN_BRACE declarations statements ctrl_statements RETURN F_VALUE ';' CLOSE_BRACE  {

    // // Search the table
    // std::string functionName = currentScope();
    // FunctionSymbol* func = table.findFunctionSymbol(functionName);
    // if (func) {
    //     func->returnValue = std::string($9);
    // }

    // if (endsWithFrame(currentScope())) {
    //     std::string frameName = extractBeforeFrame(currentScope());
    //     Frame* framePtr = table.findFrame(frameName);
    //     if (framePtr) {
    //         framePtr->;
    //     } else {
    //         yyerror(("Frame not defined: " + frameName).c_str());
    //     }
    // } else {
    //     table.addFunctionSymbol(function);
    // }

    leaveScope();
}
| F_START TYPE ID {
    FunctionSymbol function;
    function.returnType = $2;
    function.name = $3;
    function.parameters = currentParameters;
    std::cout << "PARAMETERS: " << currentParameters.size() << std::endl;
    function.definedInClass = currentScope();
    
    if (endsWithFrame(currentScope())) {
        std::string frameName = extractBeforeFrame(currentScope());
        Frame* framePtr = table.findFrame(frameName);
        if (framePtr) {
            framePtr->addFunctionSymbol(function);
        } else {
            yyerror(("Frame not defined: " + frameName).c_str());
        }
    } else {
        table.addFunctionSymbol(function);
    }

    initParameters();
    enterScope($3);
}
'(' parameters ')' OPEN_BRACE declarations statements ctrl_statements RETURN F_VALUE ';' CLOSE_BRACE
{
    
    leaveScope();
}
;

statements : statement ';' | statements statement ';';

F_VALUE : ID | NR | FLOAT | BOOL | STRING | CHAR;

parameters : 
| parameter_declaration
| parameters ',' parameter_declaration
;

parameter_declaration : TYPE ID {
    addParameter($1, $2);
}

block : BGIN declarations list END  
     ;

list : statement ';' 
     | list statement ';'
     | field_access
     | list field_access
     | method_call
     | list method_call 
     | ctrl_statements ';'
     | list ctrl_statements ';'
     | predifined_functions
     | list predifined_functions
     ;

predifined_functions : EVAL '(' expr ')' ';' {
    std::cout << "Evaluated expression value: " << static_cast<ASTNode*>($3)->evaluate(table) <<
    " At line: " << yylineno << std::endl;
}
| TYPEOF '(' expr ')' ';' {
    std::cout << "Type of expression: " << static_cast<ASTNode*>($3)->varType <<
    " At line: " << yylineno << std::endl;
}
;

statement: ID ASSIGN expr {
    Symbol* sym = nullptr;
    if (endsWithFrame(currentScope())) {
        std::string frameName = extractBeforeFrame(currentScope());
        Frame* framePtr = table.findFrame(frameName);
        if (framePtr) {
            sym = framePtr->findSymbol($1);
        }
        if (sym == nullptr) {
            yyerror(("Variable not defined in frame: " + std::string($1)).c_str());
        }
    } else {
        sym = table.findSymbol($1);
        if (sym == nullptr) {
            yyerror(("Variable not defined: " + std::string($1)).c_str());
        }
    }

    if (sym != nullptr) {
        ASTNode* exprNode = static_cast<ASTNode*>($3);
        if (exprNode != nullptr) {
            double result = exprNode->evaluate(table);
            std::cout << "Value of " << std::string($1) << ": " << result << std::endl;
            if (sym->type != exprNode->varType) {
                yyerror(("Type mismatch in assignment. L-type:" + sym->type +
                " R-type:" + exprNode->varType).c_str());
            }
            else if (sym->isConstant) {
                yyerror(("Cannot assign to constant variable: " + sym->name).c_str());
            }
            else {
                sym->value = std::to_string(result);
            }
        } else {
            yyerror("Invalid expression.");
        }
    }
}
//     | ID ASSIGN ID {
//     Symbol* sym1 = table.findSymbol($1);
//     if (sym1 == nullptr) {
//         yyerror(("Variable not defined: " + std::string($1)).c_str());
//     }
//     else {
//         Symbol* sym2 = table.findSymbol($3);
//         if (sym2 == nullptr) {
//             yyerror(("Variable not defined: " + std::string($3)).c_str());
//         }
//         else {
//             if (sym1->type != sym2->type) {
//                 yyerror(("Type mismatch in assignment. L-type:" + sym1->type +
//                 " R-type:" + sym2->type).c_str());
//             }
//             else if (sym1->isConstant == 1) {
//                 yyerror(("Cannot assign to constant variable: " + sym1->name).c_str());
//             }
//             else {
//                 sym1->value = sym2->value;
//             }
//         }
//     }
// }
// | ID ASSIGN NR {
//     Symbol* sym = table.findSymbol($1);
//     if (sym == nullptr) {
//         yyerror(("Variable not defined: " + std::string($1)).c_str());
//     }
//     else {
//         if (sym->type != "int") {
//             yyerror(("Type mismatch in assignment. L-type:" + sym->type +
//             " R-type:int").c_str());
//         }
//         else if (sym->isConstant == 1) {
//             yyerror(("Cannot assign to constant variable: " + sym->name).c_str());
//         }
//         else {
//             sym->value = std::to_string($3);
//         }
//     }
// }
// | ID ASSIGN FLOAT {
//     Symbol* sym = table.findSymbol($1);
//     if (sym == nullptr) {
//         yyerror(("Variable not defined: " + std::string($1)).c_str());
//     }
//     else {
//         if (sym->type != "float") {
//             yyerror(("Type mismatch in assignment. L-type:" + sym->type +
//             " R-type:float").c_str());
//         }
//         else if (sym->isConstant == 1) {
//             yyerror(("Cannot assign to constant variable: " + sym->name).c_str());
//         }
//         else {
//             sym->value = std::to_string($3);
//         }
//     }

// }  	
// | ID ASSIGN BOOL {
//     Symbol* sym = table.findSymbol($1);
//     if (sym == nullptr) {
//         yyerror(("Variable not defined: " + std::string($1)).c_str());
//     }
//     else {
//         if (sym->type != "bool") {
//             yyerror(("Type mismatch in assignment. L-type:" + sym->type +
//             " R-type:bool").c_str());
//         }
//         else if (sym->isConstant == 1) {
//             yyerror(("Cannot assign to constant variable: " + sym->name).c_str());
//         }
//         else {
//             std::string boolValue = ($3) ? "true" : "false";
//             sym->value = boolValue;
//         }
//     }

// }	 
| ID '(' call_list ')' {
    FunctionSymbol* sym = table.findFunctionSymbol($1);
    if (sym == nullptr) {
        yyerror(("Function not defined: " + std::string($1)).c_str());
    }
    else {
        std::vector<std::string> argTypes = splitTypes($3); 
        if (sym->parameters.size() != argTypes.size()) {
            yyerror(("Incorrect number of arguments in function '" + sym->name + "' call.").c_str());
        } else {
            for (size_t i = 0; i < argTypes.size(); ++i) {
                if (argTypes[i] != sym->parameters[i].type) {
                    yyerror("Type mismatch in function call arguments.");
                    break;
                }

                // Get the value of the function 

            }
        }
    }
    free($3); 
}
;

field_access: ID '.' ID ';' {
    Frame* frame = table.findFrame($1);
    if (frame == nullptr) {
        yyerror(("Frame not defined: " + std::string($1)).c_str());
    } else {
        Symbol* sym = frame->findSymbol($3);
        if (sym == nullptr) {
            yyerror(("Symbol not defined in frame '" + std::string($1) + "': " + std::string($3)).c_str());
        } else {
            // Do I just want to suport this or should this actually do something?
        }
    }
}
;

method_call: 
    ID '.' ID '(' call_list ')' ';' {
        Frame* frame = table.findFrame($1);
        if (frame == nullptr) {
            yyerror(("Frame not defined: " + std::string($1)).c_str());
        } else {
            FunctionSymbol* sym = frame->findFunctionSymbol($3);
            if (sym == nullptr) {
                yyerror(("Method not defined in frame '" + std::string($1) + "': " + std::string($3)).c_str());
            } else {
                std::cout << "METHOD ARGS: " << std::string($5) << std::endl;
                std::vector<std::string> argTypes = splitTypes($5); 
                if (sym->parameters.size() != argTypes.size()) {
                    std::cout << "ARG COUNT: " << sym->parameters.size() << std::endl;
                    yyerror(("Incorrect number of arguments in method '" + sym->name + "' call.").c_str());
                } else {
                    for (size_t i = 0; i < argTypes.size(); ++i) {
                        if (argTypes[i] != sym->parameters[i].type) {
                            yyerror("Type mismatch in method call arguments.");
                            break;
                        }
                    }
                    // Get the value of the method
                }
            }
        }
        free($5); 
    }
| ID '.' ID '(' ')' ';' {
        Frame* frame = table.findFrame($1);
        if (frame == nullptr) {
            yyerror(("Frame not defined: " + std::string($1)).c_str());
        } else {
            FunctionSymbol* sym = frame->findFunctionSymbol($3);
            if (sym == nullptr) {
                yyerror(("Method not defined in frame '" + std::string($1) + "': " + std::string($3)).c_str());
            } else if (!sym->parameters.empty()) {
                yyerror(("Method '" + sym->name + "' expects arguments.").c_str());
            }
        }
    }
;

call_arguments:
    ID {
        Symbol* sym = table.findSymbol($1);
        if (sym != nullptr) {
            $$ = strdup(sym->type.c_str());
        }
    }
    | NR { $$ = strdup("int"); }
    | FLOAT { $$ = strdup("float"); }
    | BOOL { $$ = strdup("bool"); }
    | STRING { $$ = strdup("string"); }
    | CHAR { $$ = strdup("char"); }
    ;

call_list:
    call_arguments {
        $$ = $1; 
    }
    | call_list ',' call_arguments {
        char* types = new char[strlen($1) + strlen($3) + 2]; // +2 for space and '\0'
        strcpy(types, $1);
        strcat(types, " ");
        strcat(types, $3);
        $$ = types;
        free($1); 
        free($3);
    }
    ;
%%
void yyerror(const char * s){
printf("error: %s at line:%d\n",s,yylineno);
}
extern void* root;
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     table.printToFile("table.txt");
}