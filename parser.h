#pragma once
#include <vector>
#include "token.h"
#include "ast.h"

class Parser
{
public:
    explicit Parser(std::vector<Token> tokens);
    BinaryExpr parse();

private:
    std::vector<Token> tokens;
    int current = 0;

    Token peek() const;
    Token advance();
    bool check(TokenType type) const;
    bool match(TokenType type);
};