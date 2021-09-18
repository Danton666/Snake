CXXC=g++
COMPFL=-c -Wall -Wextra -std=c++14
LINKFL=-o
LIB=-lsfml-window -lsfml-graphics -lsfml-system

SRC=./src/

PRJCT=Snake

TARGETS=snake.o run.o apple.o main.o tools.o

all: $(TARGETS)
	$(CXXC) $(LINKFL) $(PRJCT) *.o $(LIB)


snake.o: $(SRC)snake.cpp
	$(CXXC) $(COMPFL) $(SRC)snake.cpp -o snake.o

apple.o: $(SRC)apple.cpp
	$(CXXC) $(COMPFL)  $(SRC)apple.cpp -o apple.o

run.o: $(SRC)run.cpp
	$(CXXC) $(COMPFL) $(SRC)run.cpp -o run.o

tools.o: $(SRC)tools.cpp
	$(CXXC) $(COMPFL) $(SRC)tools.cpp -o tools.o

main.o: $(SRC)main.cpp
	$(CXXC) $(COMPFL) $(SRC)main.cpp -o main.o

.PHONY:
	clean, delete
clean:
	rm -rf *.o

delete:
	rm -f Snake
