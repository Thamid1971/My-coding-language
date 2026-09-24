#include "compiler.h"
#include <stdexcept>
#include <iostream>

Bytecode Compiler::compile(Expr* expr) {
    code.clear();
    compileExpr(expr);
    code.push_back({Opcode::RETURN, ""});
    
    // DEBUG: print bytecode
    std::cerr << "=== BYTECODE ===\n";
    for (size_t i = 0; i < code.size(); i++) {
        std::cerr << i << ": ";
        switch (code[i].op) {
            case Opcode::PUSH_CONST: std::cerr << "PUSH_CONST " << code[i].arg; break;
            case Opcode::LOAD_VAR: std::cerr << "LOAD_VAR " << code[i].arg; break;
            case Opcode::STORE_VAR: std::cerr << "STORE_VAR " << code[i].arg; break;
            case Opcode::ADD: std::cerr << "ADD"; break;
            case Opcode::SUB: std::cerr << "SUB"; break;
            case Opcode::MULT: std::cerr << "MULT"; break;
            case Opcode::DIV: std::cerr << "DIV"; break;
            case Opcode::RETURN: std::cerr << "RETURN"; break;
        }
        std::cerr << "\n";
    }
    
    return code;
}

void Compiler::compileExpr(Expr* expr) {
    if (auto* lit = dynamic_cast<Literal*>(expr)) {
        code.push_back({Opcode::PUSH_CONST, std::to_string(lit->value)});
    }
    else if (auto* var = dynamic_cast<Variable*>(expr)) {
        code.push_back({Opcode::LOAD_VAR, var->name});
    }
    else if (auto* binop = dynamic_cast<BinaryOp*>(expr)) {
        compileExpr(binop->left);
        compileExpr(binop->right);
        switch (binop->op) {
            case '+': code.push_back({Opcode::ADD, ""}); break;
            case '-': code.push_back({Opcode::SUB, ""}); break;
            case '*': code.push_back({Opcode::MULT, ""}); break;
            case '/': code.push_back({Opcode::DIV, ""}); break;
        }
    }
    else {
        throw std::runtime_error("Unknown expression type");
    }
}