#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "vm.h"

int main()
{
    std::ifstream file("main.cp");

    if (!file.is_open())
    {
        std::cerr << "Failed to open main.cp\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer;
    auto tokens = lexer.scanTokens(source);

    Parser parser(tokens);
    Expr *finalExpr = parser.parse();

    Compiler compiler;
    VM vm;

    // Execute all let statements first (no RETURN)
    for (const auto &[varName, expr] : parser.letStatements)
    {
        Bytecode code = compiler.compile(expr);
        code.pop_back(); // remove the RETURN
        code.push_back({Opcode::STORE_VAR, varName});
        code.push_back({Opcode::RETURN, ""}); // add RETURN back
        vm.execute(code);
    }

    // Then compile and execute the final expression (with RETURN)
    Bytecode finalCode = compiler.compile(finalExpr);
    int result = vm.execute(finalCode);

    std::cout << result << '\n';

    return 0;
}