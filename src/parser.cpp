#include "parser.h"
#include <stdexcept>

Parser::Parser(std::vector<Token> tokens) 
    : tokens(tokens) {}

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

int Parser::getPrecedence(char op) const {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

Expr* Parser::parsePrimary() {
    if (check(TokenType::NUMBER)) {
        int value = std::stoi(advance().value);
        return new Literal(value);
    }

    if (check(TokenType::IDENTIFIER)) {
        std::string name = advance().value;
        return new Variable(name);
    }

    throw std::runtime_error("Expected a number or variable");
}

Expr* Parser::parseExpression(int minPrecedence) {
    Expr* left = parsePrimary();

    while (check(TokenType::OPERATOR) && getPrecedence(peek().value[0]) >= minPrecedence) {
        char op_char = advance().value[0];
        int op_prec = getPrecedence(op_char);
        Expr* right = parseExpression(op_prec + 1);

        left = new BinaryOp(left, op_char, right);
    }

    return left;
}

Expr* Parser::parse() {
    // Handle multiple let statements
    while (check(TokenType::LET)) {
        advance();  // consume "let"
        
        if (!check(TokenType::IDENTIFIER)) {
            throw std::runtime_error("Expected variable name after let");
        }
        advance();  // just skip the variable name for now
        
        if (!match(TokenType::EQUAL)) {
            throw std::runtime_error("Expected = after variable name");
        }

        parseExpression(0);  // parse but don't use the result yet

        if (!match(TokenType::SEMICOLON)) {
            throw std::runtime_error("Expected ; after expression");
        }
    }
    
    // After all let statements, parse and return the final expression
    return parseExpression(0);
}