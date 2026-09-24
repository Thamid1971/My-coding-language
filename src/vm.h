#pragma once
#include "bytecode.h"
#include <unordered_map>
#include <vector>

class VM {
public:
    int execute(const Bytecode& bytecode);

private:
    std::vector<int> stack;
    std::unordered_map<std::string, int> variables;
};