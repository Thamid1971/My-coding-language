#pragma once
#include <vector>
#include "token.h"
#include "ast.h"
#include "interpreter.h"

class Parser {
public:
    explicit Parser(std::vector<Token> tokens, Interpreter* interp);
    Expr* parse();

private:
    std::vector<Token> tokens;
    Interpreter* interpreter;
    int current = 0;

    Token peek() const;
    Token advance();
    bool check(TokenType type) const;
    bool match(TokenType type);
    
    Expr* parseExpression(int minPrecedence);
    Expr* parsePrimary();
    int getPrecedence(char op) const;
};