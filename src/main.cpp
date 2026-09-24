#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "vm.h"

int main() {
    std::ifstream file("main.cp");

    if (!file.is_open()) {
        std::cerr << "Failed to open main.cp\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer;
    auto tokens = lexer.scanTokens(source);

    Parser parser(tokens);
    Expr* expr = parser.parse();

    Compiler compiler;
    Bytecode bytecode = compiler.compile(expr);

    VM vm;
    int result = vm.execute(bytecode);

    std::cout << result << '\n';

    return 0;
}