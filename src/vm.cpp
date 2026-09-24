#include "vm.h"
#include <stdexcept>


int VM::execute(const Bytecode& bytecode) {
    stack.clear();
    
    for (const auto& instr : bytecode) {
        switch (instr.op) {
            case Opcode::PUSH_CONST: {
                stack.push_back(std::stoi(instr.arg));
                break;
            }
            case Opcode::LOAD_VAR: {
                if (variables.find(instr.arg) == variables.end()) {
                    throw std::runtime_error("Undefined variable: " + instr.arg);
                }
                stack.push_back(variables[instr.arg]);
                break;
            }
            case Opcode::STORE_VAR: {
                if (stack.empty()) throw std::runtime_error("Stack underflow");
                variables[instr.arg] = stack.back();
                stack.pop_back();
                break;
            }
            case Opcode::ADD: {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                stack.push_back(left + right);
                break;
            }
            case Opcode::SUB: {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                stack.push_back(left - right);
                break;
            }
            case Opcode::MULT: {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                stack.push_back(left * right);
                break;
            }
            case Opcode::DIV: {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                if (right == 0) throw std::runtime_error("Division by zero");
                stack.push_back(left / right);
                break;
            }
            case Opcode::RETURN: {
                return stack.back();
            }
        }
    }
    throw std::runtime_error("No return instruction");
}