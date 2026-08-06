#pragma once
#include "ast.h"

class Interpreter {
public:
    int evaluate(const BinaryExpr& expr);
};