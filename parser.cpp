#include "parser.h"
#include <stdexcept>

Parser::Parser(std::vector<Token> tokens) : tokens(tokens) {}

Token Parser::peek() const {
    return tokens[current];
}

Token Parser::advance() {
    Token current_token = tokens[current];
    current++;
    return current_token;
}

bool Parser::check(TokenType type) const {
    return peek().type == type;
}

bool Parser::match(TokenType type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

BinaryExpr Parser::parse() {
    if (!check(TokenType::NUMBER)) {
        throw std::runtime_error("Expected a number");
    }
    int left = std::stoi(advance().value);

    if (!check(TokenType::OPERATOR)) {
        throw std::runtime_error("Expected an operator");
    }
    char op = advance().value[0];

    if (!check(TokenType::NUMBER)) {
        throw std::runtime_error("Expected a number");
    }
    int right = std::stoi(advance().value);

    if (!check(TokenType::END_OF_FILE)) {
        throw std::runtime_error("Expected end of expression");
    }

    return {left, op, right};
}
