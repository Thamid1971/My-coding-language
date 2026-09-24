CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC = main.cpp lexer.cpp parser.cpp compiler.cpp vm.cpp
BIN = calc

$(BIN): $(SRC) *.h
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SRC)

clean:
	rm -f $(BIN)

.PHONY: clean