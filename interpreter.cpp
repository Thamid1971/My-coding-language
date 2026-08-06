#include "interpreter.h"
#include <stdexcept>

int Interpreter::evaluate(const BinaryExpr& expr) {
    switch (expr.op) {
        case '+': return expr.left + expr.right;
        case '-': return expr.left - expr.right;
        case '*': return expr.left * expr.right;
        case '/': return expr.left / expr.right;
        default: throw std::runtime_error("Unknown operator");
    }
}