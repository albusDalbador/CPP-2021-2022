OUTPUT = main

CXX=g++
#CXXFLAGS+=-Wall -O0 $(GXX_FLAGS) -std=c++11
#CXXFLAGS+=-g
CXXFLAGS+=-E

#Dependency for the output file
#DEP_FLAGS=-MMD
#DEP_FLAGS+=-MP

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=${SRC:.cpp=.d}

#Add dependency generation to the compiler options
CXXFLAGS+=$(DEP_FLAGS)

all: $(OUTPUT)
	@echo Main program created

$(OUTPUT): $(OBJ)
	@$(CXX) $(OBJ) -o $@
	
%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) $<
	

.PHONY: clean run

clean:
	@rm -f run $(OBJ) *.d

-include $(DEP) 

run:
	./main
