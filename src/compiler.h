#pragma once
#include "ast.h"
#include "bytecode.h"

class Compiler {
public:
    Bytecode compile(Expr* expr);

private:
    Bytecode code;
    void compileExpr(Expr* expr);
};