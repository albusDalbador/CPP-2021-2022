
CC = g++

LIBS = -lm

all:main 

main: main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -c -o main.o


clean:
	@echo Removing old files
	@rm -f *.o main

run:
	./main
OUPUT = main


#second variant
# CXX=g++

# CXXFLAGS=-Wall -O0 $(GXX_FLAGS) -std=c++11

# SRC=$(wilcard *.cpp) #variables defining
# OBJ=$(SRC:.cpp=.o)


# all: $(OUPUT)
# 	@echo Main program created

# $(OUPUT): $(OBJ)
# 	@$(CXX) $(OBJ) -o $@

# %.o: %.cpp
# 	@$(CXX) -c $(CXXFLAGS) $<

# .PHONY: clean run #commands run by default

# clean:
# 	@rm -f run $(OBJ) 

# run:
# 	./main



 