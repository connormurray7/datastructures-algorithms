CXX		= clang++
SOURCES		= $(wildcard *.cpp)
OBJECTS		= $(SOURCES:%.cpp=%.o)
EXECUTABLE	= main
VALGRIND	= valgrind --leak-check=yes
CXXFLAGS	= -std=c++14 -stdlib=libc++ -Wall -Werror -Wextra -pedantic

release: CXXFLAGS += -O3
release: all

debug: CXXFLAGS += -g
debug: clean all

profile: CXXFLAGS += -pg
profile: clean all

run: all
run:
	./$(EXECUTEABLE)

all: $(OBJECTS)
	 $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

Vector.o: ../data_structures/vector/Vector.cpp

test_vector.o: test_vector.cpp

%.o:
	 $(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

valgrind: debug
valgrind:
	$(VALGRIND) ./$(EXECUTABLE)

.PHONY: all release debug profile clean valgrind

.SUFFIXES:
