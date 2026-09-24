#pragma once
#include <string>

// Base class for all expressions
struct Expr {
    virtual ~Expr() = default;
};

// A number literal: 5, 42, etc.
struct Literal : Expr {
    int value;
    Literal(int val) : value(val) {}
};

// A variable reference: x, y, etc.
struct Variable : Expr {
    std::string name;
    Variable(std::string n) : name(n) {}
};

// A binary operation: 2+3, x*y, etc.
struct BinaryOp : Expr {
    Expr* left;
    char op;
    Expr* right;
    BinaryOp(Expr* l, char o, Expr* r) : left(l), op(o), right(r) {}
};