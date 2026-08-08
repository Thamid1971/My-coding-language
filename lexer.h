#pragma once

#include <vector>
#include <string>
#include <cctype>
#include "token.h"

class Lexer
{
public:
    std::vector<Token> tokens;
    std::string number;

    std::vector<Token> scanTokens(const std::string &SourceCode)
    {
        tokens.clear();
        number.clear();

        for (int i = 0; i < SourceCode.size(); i++)
        {
            char c = SourceCode[i];

            if (std::isdigit(c))
            {
                number.clear();

                while (i < SourceCode.size() && std::isdigit(SourceCode[i]))
                {
                    number += SourceCode[i];
                    i++;
                }

                i--;

                tokens.push_back({
                    TokenType::NUMBER,
                    number
                });
            }
            else if (c == '+')
            {
                tokens.push_back({
                    TokenType::OPERATOR,
                    std::string(1, c)
                });
            }
            else if (c == '-')
            {
                tokens.push_back({
                    TokenType::OPERATOR,
                    std::string(1, c)
                });
            }
            else if (c == '*')
            {
                tokens.push_back({
                    TokenType::OPERATOR,
                    std::string(1, c)
                });
            }
            else if (c == '/')
            {
                tokens.push_back({
                    TokenType::OPERATOR,
                    std::string(1, c)
                });
            }
            else if (c == '=')
            {
                tokens.push_back({
                    TokenType::EQUAL,
                    "="
                });
            }
            else if (c == ';')
            {
                tokens.push_back({
                    TokenType::SEMICOLON,
                    ";"
                });
            }
            else if (std::isalpha(c) || c == '_')
            {
                std::string text = "";
                while (i < SourceCode.size() && (std::isalnum(SourceCode[i]) || SourceCode[i] == '_'))
                {
                    text += SourceCode[i];
                    i++;
                }
                i--;  // back up one

                if (text == "let")
                {
                    tokens.push_back({TokenType::LET, text});
                }
                else
                {
                    tokens.push_back({TokenType::IDENTIFIER, text});
                }
            }
            else if (c == ' ' || c == '\n' || c == '\t')
            {
                // skip whitespace
            }
        }

        tokens.push_back({
            TokenType::END_OF_FILE,
            ""
        });

        return tokens;
    }

private:
    char peek(int index, std::string src)
    {
        return src[index];
    }
};