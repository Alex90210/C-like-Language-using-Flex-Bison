#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include <sstream>

class Symbol {
public:
    std::string name;
    std::string type; 
    int arraySize {1};
    std::string value;
    std::vector<int> intValues;
    std::vector<double> values;

    std::vector<char> charValues;
    std::vector<std::string> stringValues;

    std::string scope;
    bool isConstant {false};
};

class FunctionSymbol {
public:
    bool isFrame {false};
    std::string name;
    std::string returnValue;
    std::string returnType;
    std::string definedInClass;
    std::vector<Symbol> parameters;
};

class Frame {
    public:
    std::string name;
    std::vector <Symbol> symbols;
    std::vector <FunctionSymbol> functionSymbols;

    void addSymbol(const Symbol& symbol) {
        symbols.push_back(symbol);
    }

    void addFunctionSymbol(const FunctionSymbol& functionSymbol) {
        functionSymbols.push_back(functionSymbol);
    }

    Symbol* findSymbol(const std::string& name) {
        for (auto& symbol : symbols) {
            if (symbol.name == name) return &symbol;
        }
        return nullptr;
    }

    FunctionSymbol* findFunctionSymbol(const std::string& name) {
        for (auto& functionSymbol : functionSymbols) {
            if (functionSymbol.name == name) return &functionSymbol;
        }
        return nullptr; 
    }
};

class SymbolTable {
    public:
    std::vector<Symbol> symbols;
    std::vector<FunctionSymbol> functionSymbols;
    std::vector<Frame> frames;


    void addSymbol(const Symbol& symbol) {
        symbols.push_back(symbol);
    }

    void addFunctionSymbol(const FunctionSymbol& functionSymbol) {
        functionSymbols.push_back(functionSymbol);
    }

    void addFrame(const Frame& frame) {
        frames.push_back(frame);
    }

    void printToFile(const std::string& filename);

    Symbol* findSymbol(const std::string& name) {
        for (auto& symbol : symbols) {
            if (symbol.name == name) return &symbol;
        }
        return nullptr;
    }

    FunctionSymbol* findFunctionSymbol(const std::string& name) {
        for (auto& functionSymbol : functionSymbols) {
            if (functionSymbol.name == name) return &functionSymbol;
        }
        return nullptr; 
    }

    Frame* findFrame(const std::string& name) {
        for (auto& frame : frames) {
            if (frame.name == name) return &frame;
        }
        return nullptr;
    }
};

void enterScope(const std::string& scopeName);
void leaveScope();
std::string currentScope();

bool isNumber(const std::string& str);
bool isFloat(const std::string& str);
bool endsWithFrame(const std::string& str);
std::string extractBeforeFrame(const std::string& str);

#endif