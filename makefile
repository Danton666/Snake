CXXC=g++
COMPFL=-c -Wall -Wextra -std=c++14
LINKFL=-o
INC=-I./Headers/
LIB=-lsfml-window -lsfml-graphics -lsfml-system

BIN=./bin/
SRC=./src/

PRJCT=Snake

TARGETS=controlMoving.o fillArrays.o isOutOfBounds.o
TARGETS+=snake.o run.o apple.o main.o

all: $(TARGETS)
	$(CXXC) $(LINKFL) $(PRJCT) $(BIN)*.o $(LIB)


snake.o: $(SRC)snake.cpp
	$(CXXC) $(COMPFL) $(SRC)snake.cpp -o $(BIN)snake.o $(INC)

apple.o: $(SRC)apple.cpp
	$(CXXC) $(COMPFL)  $(SRC)apple.cpp -o $(BIN)apple.o $(INC)

run.o: $(SRC)run/run.cpp
	$(CXXC) $(COMPFL) $(SRC)run/run.cpp -o $(BIN)run.o $(INC)

main.o: $(SRC)main.cpp
	$(CXXC) $(COMPFL) $(SRC)main.cpp -o $(BIN)main.o $(INC)

controlMoving.o: $(SRC)run/controlMoving.cpp
	$(CXXC) $(COMPFL) $(SRC)run/controlMoving.cpp -o $(BIN)controlMoving.o $(INC)

fillArrays.o: $(SRC)run/fillArrays.cpp
	$(CXXC) $(COMPFL) $(SRC)run/fillArrays.cpp -o $(BIN)fillArrays.o $(INC)

isOutOfBounds.o: $(SRC)run/isOutOfBounds.cpp
	$(CXXC) $(COMPFL) $(SRC)run/isOutOfBounds.cpp -o $(BIN)isOutOfBounds.o $(INC)


.PHONY:
	clean, delete
clean:
	rm -rf $(BIN)*.o

delete:
	rm -f Snake

