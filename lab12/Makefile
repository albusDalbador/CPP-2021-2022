CXX = g++
EXEC = main
CXXFLAGS = $(flag) -std=c++17 -Wall -pedantic #-DBASIC #-DERROR
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: clean $(EXEC) run

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

error: $(EXEC) run clear
error: flag=-DERROR

clean:
	rm -rf *.o $(EXEC)

clear:
	rm -rf *.o

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean clear run check