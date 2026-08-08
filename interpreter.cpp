#include "interpreter.h"
#include <stdexcept>

int Interpreter::evaluate(Expr* expr) {
    // Check if it's a Literal (a number)
    if (auto* lit = dynamic_cast<Literal*>(expr)) {
        return lit->value;
    }
    
    // Check if it's a Variable (a variable reference)
    if (auto* var = dynamic_cast<Variable*>(expr)) {
        if (variables.find(var->name) == variables.end()) {
            throw std::runtime_error("Undefined variable: " + var->name);
        }
        return variables[var->name];
    }
    
    // Check if it's a BinaryOp (an operation like x+3)
    if (auto* binop = dynamic_cast<BinaryOp*>(expr)) {
        int left = evaluate(binop->left);
        int right = evaluate(binop->right);
        
        switch (binop->op) {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': return left / right;
            default: throw std::runtime_error("Unknown operator");
        }
    }
    
    throw std::runtime_error("Unknown expression type");
}

void Interpreter::setVariable(const std::string& name, int value) {
    variables[name] = value;
}