CXX			= clang++
SOURCES 	= $(wildcard *.cpp)
OBJECTS		= $(SOURCES:%.cpp=%.o)
EXECUTABLE 	= main

VALGRIND    = valgrind --leak-check=yes

CXXFLAGS = -std=c++14 -stdlib=libc++ -Wall -Werror -Wextra -pedantic

release: CXXFLAGS += -O3
release: all

debug: CXXFLAGS += -g
debug: clean all

# make profile - will compile "all" with $(CXXFLAGS) and the -pg flag
profile: CXXFLAGS += -pg
profile: clean all

run: all
run:
	./$(EXECUTEABLE)

all: $(OBJECTS)
	 $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

BinaryTree.o: BinaryTree.cpp

main.o: main.cpp

%.o:
	 $(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

valgrind: debug
valgrind:
	$(VALGRIND) ./$(EXECUTABLE)

.PHONY: all release debug profile clean valgrind

.SUFFIXES:
