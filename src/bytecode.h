#pragma once
#include <vector>
#include <string>

enum class Opcode {
    PUSH_CONST,    // push a number
    LOAD_VAR,      // load variable
    STORE_VAR,     // store in variable
    ADD, SUB, MULT, DIV,
    RETURN
};

struct Instruction {
    Opcode op;
    std::string arg;  // for PUSH_CONST, LOAD_VAR, STORE_VAR
};

using Bytecode = std::vector<Instruction>;