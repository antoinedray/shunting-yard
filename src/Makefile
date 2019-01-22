# Makefile

CXX=g++
CXXFLAGS=-g -Wall -Wextra -Werror -pedantic -std=c++17
LDFLAGS=-g

SRC=main.cc shunting-yard.cc
OBJ=$(subst .cc,.o,$(SRC))

.PHONY: all clean

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o main $(OBJ)

clean:
	${RM} ${OBJ}
	${RM} main

# End
