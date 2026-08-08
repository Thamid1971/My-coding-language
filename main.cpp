// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include "lexer.h"
// #include "parser.h"
// #include "interpreter.h"

// int main() {
//     std::ifstream file("main.txt");

//     if (!file.is_open()) {
//         std::cerr << "Failed to open main.txt\n";
//         return 1;
//     }

//     std::stringstream buffer;
//     buffer << file.rdbuf();
//     std::string source = buffer.str();

//     Lexer lexer;
//     auto tokens = lexer.scanTokens(source);

//     Parser parser(tokens);
//     Expr* expr = parser.parse();

//     Interpreter interpreter;
//     int result = interpreter.evaluate(expr);

//     std::cout << result << '\n';

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main() {
    std::ifstream file("main.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open main.txt\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer;
    auto tokens = lexer.scanTokens(source);

    Interpreter interpreter;
    Parser parser(tokens, &interpreter);
    Expr* expr = parser.parse();

    int result = interpreter.evaluate(expr);
    std::cout << result << '\n';

    return 0;
}