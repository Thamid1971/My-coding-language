#pragma once
#include "ast.h"
#include <unordered_map>

class Interpreter {
public:
    int evaluate(Expr* expr);
    void setVariable(const std::string& name, int value);

private:
    std::unordered_map<std::string, int> variables;  // stores variable values
};