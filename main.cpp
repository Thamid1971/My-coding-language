// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include "lexer.h"

// int main()
// {
//     std::ifstream file("main.txt");

//     if (!file.is_open())
//     {
//         std::cerr << "Failed to open main.txt\n";
//         return 1;
//     }

//     // Read the entire file into a string
//     std::stringstream buffer;
//     buffer << file.rdbuf();
//     std::string source = buffer.str();

//     Lexer lexer;
//     std::vector<Token> tokens = lexer.scanTokens(source);

//     for (const Token &t : tokens)
//     {
//         std::cout << "type=" << static_cast<int>(t.type)
//                   << " value='" << t.value << "'\n";
//     }

//     return 0;
// }

#include <iostream>
#include "lexer.h"
#include "parser.h"

int main() {
    std::string source = "12+7";
    
    Lexer lexer;
    auto tokens = lexer.scanTokens(source);
    
    Parser parser(tokens);
    BinaryExpr expr = parser.parse();
    
    // TODO: evaluate the expr and print result
    
    return 0;
}