#ifndef AST_H
#define AST_H

#include <string>
#include <iostream>
#include "utils.h"

class ASTNode {
public:
    enum NodeType { NUMBER, OPERATOR, IDENTIFIER, BOOL_OPERATOR, BOOL_VALUE, ARRAY_ACCESS };

    NodeType type;
    std::string varType {"imaginary type"};
    std::string value;
    ASTNode* left;
    ASTNode* right;

    ASTNode(NodeType type, std::string varType, std::string value, ASTNode* left = nullptr, ASTNode* right = nullptr)
    : type(type), varType(std::move(varType)), value(std::move(value)), left(left), right(right) {}


    ~ASTNode() {
        delete left;
        delete right;
    }

    double evaluate(SymbolTable& table){
        if (this == nullptr) return 0;

        switch (type) {
            case NUMBER: {
                if (isNumber(value)) {
                    varType = "int";
                    return std::stoi(value);
                }
                else if (isFloat(value)) {
                    varType = "float";
                    return std::stof(value);
                }
            }

            case OPERATOR: {
                double leftValue = left ? left->evaluate(table) : 0;
                double rightValue = right ? right->evaluate(table) : 0;

                if (left->varType != right->varType) {
                    std::cout << "Error: Type mismatch. L-type: " + left->varType
                            + " R-type: " + right->varType << std::endl;
                    return -111;
                }

                varType = left->varType; // Set the varType of the operator node

                if (value == "+") {
                    return leftValue + rightValue;
                } else if (value == "-") {
                    return leftValue - rightValue;
                } else if (value == "*") {
                    return leftValue * rightValue;
                } else if (value == "/") {
                    if (rightValue == 0) {
                        std::cout << "Error: Division by zero." << std::endl;
                    }
                    return leftValue / rightValue;
                }
                break;
            }

            case IDENTIFIER: {
                Symbol* sym = table.findSymbol(value);
                if (sym != nullptr) {
                    if (isNumber(sym->value)) {
                        varType = sym->type;
                        return std::stoi(sym->value);
                    }
                    else if (isFloat(sym->value)) {
                        varType = sym->type;
                        return std::stof(sym->value);
                    }
                    else if (sym->type == "bool") {
                        varType = sym->type;
                        return -111;
                    }
                    else if (sym->type == "string") {
                        varType = sym->type;
                        return -111;
                    }
                    else if (sym->type == "char") {
                        varType = sym->type;
                        return -111;
                    }
                } 
                else {
                    bool found = false;
                    for (auto& frame : table.frames) {
                        sym = frame.findSymbol(value);
                        if (sym != nullptr) {
                            found = true;
                            if (isNumber(sym->value)) {
                                varType = sym->type;
                                return std::stoi(sym->value);
                            }
                            else if (isFloat(sym->value)) {
                                varType = sym->type;
                                return std::stof(sym->value);
                            }
                            else if (sym->type == "bool") {
                                varType = sym->type;
                                return -111;
                            }
                            else if (sym->type == "string") {
                                varType = sym->type;
                                return -111;
                            }
                            else if (sym->type == "char") {
                                varType = sym->type;
                                return -111;
                            }
                            break;
                        }
                    }
                    if (!found) {
                        std::cout << "Error: Symbol '" << value << "' not found in any frame." << std::endl;
                    }
                }
                return 0;
            }
            case BOOL_OPERATOR: {
                bool leftValue = left ? static_cast<bool>(left->evaluate(table)) : false;
                bool rightValue = right ? static_cast<bool>(right->evaluate(table)) : false;

                if (value == "OR") {
                    varType = "bool";   
                    return leftValue || rightValue;
                } else if (value == "AND") {
                    varType = "bool";
                    return leftValue && rightValue;
                } else if (value == "!") {
                    varType = "bool";
                    return !leftValue;
                }
                break;
            }
            case BOOL_VALUE: {
                varType = "bool";
                return value == "true";
            }
            case ARRAY_ACCESS: {
                if (right == nullptr) {
                    std::cout << "Error: Array index not provided." << std::endl;
                    return -1;
                }

                int index = static_cast<int>(right->evaluate(table));
                Symbol* sym = table.findSymbol(value);
                if (sym != nullptr && index >= 0 && index < sym->arraySize) {
                    return sym->values[index];
                } else {
                    std::cout << "Error: Invalid array access." << std::endl;
                    return -1;
                }
            }

        }

        return 0; 
    }

    void print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }

        std::cout << value << std::endl;

        if (left) left->print(depth + 1);
        if (right) right->print(depth + 1);
    }
};

#endif