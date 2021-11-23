OUTPUT = main

CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS) -std=c++11
#CXXFLAGS+=-g
# CXXFLAGS+=-E

#Dependency for the output file
#DEP_FLAGS=-MMD
#DEP_FLAGS+=-MP 

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC)) 
# OBJ=$(SRC:.cpp=.o) #shorthand of of above expression
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
	@echo Cleaning up...
	@rm -f run $(OBJ) *.d $(OUTPUT)

-include $(DEP) 

run:
	./main

# depend:
# 	@echo $(word 1, $(DEP))
# 	@cat $(word 1, $(DEP))
# just the way to print certain word from $(DEP)