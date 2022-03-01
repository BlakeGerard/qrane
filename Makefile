SCANNER = qrane-scanner
GRAMMAR = qrane-parser

# Binary target
BIN = qrane

# Library target
TLIB = libqrane.so

#ISL = ./lib/isl
#ISL_LIBS = $(ISL)/lib
#ISL_INCL = $(ISL)/include

BARVINOK = ./lib/barvinok
BARVINOK_LIBS = $(BARVINOK)/lib
BARVINOK_INCL = $(BARVINOK)/include

NTL = ./lib/ntl
NTL_LIBS = $(NTL)/lib
NTL_INCL = $(NTL)/include

BISON = ./lib/bison
BISON_LIBS = $(BISON)/lib
BISON_BIN = $(BISON)/bin/bison

PYTHON_HOME = $(QRANE_CONDA_BASE)/lib
PYTHON_INCL = $(QRANE_CONDA_BASE)/include/python3.9
PYTHON_HEAD = /usr/include/python3.9/

AQUMA_INCL = $(AQUMA_HOME)

INCL = -I. -I./include -I$(AQUMA_INCL) -I$(PYTHON_HEAD) -I$(PYTHON_INCL) -I$(PYTHON_HOME) -I$(BARVINOK_INCL) -I$(NTL_INCL)
LIBS = -L. -L$(PYTHON_HOME) -lpython3.9 -L$(BARVINOK_LIBS) -L$(NTL_LIBS)  -lstdc++ -lbarvinok -lisl -lpolylibgmp -lntl -L$(BISON_LIBS) -ly -lgmp -ldl -lutil 

SRCS = qrane_driver.cpp $(SCANNER).c $(GRAMMAR).c ./src/*
LIBSRCS = qrane_api.cpp $(SCANNER).c $(GRAMMAR).c ./src/*

FLEX_BIN = flex
CXX = clang++
CXXFLAGS = -Wall -g -O3 -fopenmp -std=c++11 -pthread -march=native
CXXLIBFLAGS = -shared -fpic

all: scanner grammar bin lib

scanner: $(SCANNER).yy
	$(FLEX_BIN) -o $(SCANNER).c $(SCANNER).yy 

grammar: $(GRAMMAR).y
	$(BISON_BIN) -o $(GRAMMAR).c $(GRAMMAR).y 

bin: $(SRCS)
	$(CXX) -o $(BIN) $(CXXFLAGS) $(INCL) $(SRCS) $(LIBS) 

lib: $(SRCS)
	$(CXX) -o $(TLIB) $(CXXFLAGS) $(CXXLIBFLAGS) $(INCL) $(LIBSRCS) $(LIBS)

clean: 
	rm qrane
