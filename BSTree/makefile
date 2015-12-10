CC=gcc
CXX=g++
RM=rm -f

CFLAGS=
CXXFLAGS=-g -Wall
CPPFLAGS=
LDFLAGS=

all:Test_BSTree.out
	
Test_BSTree.out:BSTree.o Main.o
	$(CXX) $(LDFLAGS) -o $@ $^

BSTree.o:BSTree.cpp BSTree.h

Main.o:Main.cpp BSTree.h

clean:
	$(RM) *.o *.out
