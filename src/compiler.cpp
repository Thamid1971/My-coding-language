#include "compiler.h"
#include <stdexcept>

Bytecode Compiler::compile(Expr* expr) {
    code.clear();
    compileExpr(expr);
    code.push_back({Opcode::RETURN, ""});
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