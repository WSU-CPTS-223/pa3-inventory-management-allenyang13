CXX = g++
CXXFLAGS = -g -Wall -std=c++14

MAIN_SRC = main.cpp Inventory.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
MAIN_EXE = mainexe

TEST_SRC = Test.cpp
TEST_EXE = testexe

all: $(MAIN_EXE)

$(MAIN_EXE): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXE) $(MAIN_OBJ)

test: $(TEST_SRC) Hash.h
	$(CXX) $(CXXFLAGS) -o $(TEST_EXE) $(TEST_SRC)
	./$(TEST_EXE)

run: $(MAIN_EXE)
	./$(MAIN_EXE)

clean:
	rm -f $(MAIN_OBJ) $(MAIN_EXE) $(TEST_EXE)

compile:
	$(CXX) $(CXXFLAGS) -o mainexe main.cpp Inventory.cpp

