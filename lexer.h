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