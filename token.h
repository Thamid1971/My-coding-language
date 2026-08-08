#pragma once
#include <string>

enum class TokenType {
    NUMBER, IDENTIFIER,
    LET,
    PLUS, MINUS, STAR, SLASH,
    LPAREN, RPAREN,
    EQUAL, SEMICOLON,
    END_OF_FILE,
    OPERATOR,
    ERROR
};

struct Token {
    TokenType type;
    std::string value;
};