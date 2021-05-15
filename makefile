CXXC=g++
COMPFL=-c -Wall -Wextra -std=c++14
LINKFL=-o
INC=-I./Headers/
LIB=-lsfml-window -lsfml-graphics -lsfml-system

BIN=./bin/
SRC=./src/

PRJCT=Snake

TARGETS=snake.o run.o apple.o main.o tools.o

all: $(TARGETS)
	$(CXXC) $(LINKFL) $(PRJCT) $(BIN)*.o $(LIB)


snake.o: $(SRC)snake.cpp
	$(CXXC) $(COMPFL) $(SRC)snake.cpp -o $(BIN)snake.o $(INC)

apple.o: $(SRC)apple.cpp
	$(CXXC) $(COMPFL)  $(SRC)apple.cpp -o $(BIN)apple.o $(INC)

run.o: $(SRC)run.cpp
	$(CXXC) $(COMPFL) $(SRC)run.cpp -o $(BIN)run.o $(INC)

tools.o: $(SRC)tools.cpp
	$(CXXC) $(COMPFL) $(SRC)tools.cpp -o $(BIN)tools.o $(INC)

main.o: $(SRC)main.cpp
	$(CXXC) $(COMPFL) $(SRC)main.cpp -o $(BIN)main.o $(INC)

.PHONY:
	clean, delete
clean:
	rm -rf $(BIN)*.o

delete:
	rm -f Snake
