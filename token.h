#pragma once
#include <string>

enum class TokenType {
    NUMBER,
    OPERATOR,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
};