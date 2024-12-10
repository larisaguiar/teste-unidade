# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/path/to/catch2/include

# Executáveis
EXEC = test_runner
SRC = main.cpp item.cpp shoppingCart.cpp testeShoppingCart.cpp testeRunner.cpp
OBJ = $(SRC:.cpp=.o)

# Regras
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
