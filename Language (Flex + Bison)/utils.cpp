#include "utils.h"

std::stack<std::string> scopeStack;

void SymbolTable::printToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string currentScope = symbols[0].scope;
    file << "Symbols:\n";
    for (const auto& symbol : symbols) {
        if (currentScope != symbol.scope) {
            file << "\n";
            currentScope = symbol.scope;
        }
        
        file << "Symbol: " << symbol.name << ", Type: " << symbol.type
             << ", Scope: " << symbol.scope << ", Is Constant: " << symbol.isConstant 
             << ", Value: " << symbol.value << "\n";
    
    }

    file << "\nFunctions:\n";
    for (const auto& functionSymbol : functionSymbols) {
        file << "Function: " << functionSymbol.name << ", Return Type: " << functionSymbol.returnType 
            << ", Scope: " << functionSymbol.definedInClass << ", Parameters: ";
        
        for (const auto& param : functionSymbol.parameters) {
            file << param.type << " " << param.name << "; ";
        }

        file << "\n";
    }

    file << "\nFrames and their Functions:\n";
    for (const auto& frame : frames) {
        file << "Frame: " << frame.name << "\n";
        
        for (const auto& functionSymbol : frame.functionSymbols) {
            file << "  Function: " << functionSymbol.name << ", Return Type: " << functionSymbol.returnType 
                << ", Defined In Class: " << frame.name << ", Parameters: ";
            
            for (const auto& param : functionSymbol.parameters) {
                file << param.type << " " << param.name << "; ";
            }

            file << "\n";
        }
    }


    file.close();
}


void enterScope(const std::string& scopeName) {
    // std::cout << "Entering scope: " << scopeName << std::endl;
    scopeStack.push(scopeName);
}

void leaveScope() {
    if (!scopeStack.empty()) {
        // std::cout << "Leaving scope: " << scopeStack.top() << std::endl;
        scopeStack.pop();
    }
}

std::string currentScope() {
    if (scopeStack.empty()) {
        // std::cout << "Current scope: global" << std::endl;
        return "global";
    }
    // std::cout << "Current scope: " << scopeStack.top() << std::endl;
    return scopeStack.top();
}

bool isNumber(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    for (char ch : str) {
        if (!isdigit(static_cast<unsigned char>(ch))) {
            return false;
        }
    }

    return true;
}

bool isFloat(const std::string& str) {
    char* end;
    std::strtod(str.c_str(), &end);
    return end != str.c_str() && *end == '\0';
}

bool endsWithFrame(const std::string& str) {
    std::string suffix = "FRAME";

    if (str.size() >= suffix.size() && 
        str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0) {
        return true;
    } else {
        return false;
    }
}

std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }

    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

std::string extractBeforeFrame(const std::string& str) {
    std::string suffix = "FRAME";
    std::size_t pos = str.rfind(suffix);

    if (pos != std::string::npos) {
        return trim(str.substr(0, pos));
    } else {
        return trim(str);
    }
}