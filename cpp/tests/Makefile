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
	chmod 755 main && ./main

all: $(OBJECTS)
	 $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

Vector.o: ../data_structures/vector/Vector.cpp
BinaryTree.o: ../data_structures/binary_tree/BinaryTree.cpp
HashSet.o: ../data_structures/map/hash_set/HashSet.cpp
HashMap.o: ../data_structures/map/hash_map/HashMap.cpp
Bucket.o: ../data_structures/map/Bucket.cpp

test_vector.o: test_vector.cpp
test_binary_tree.o: test_binary_tree.cpp
test_hash_set.o: test_hash_set.cpp
test_hash_map.o: test_hash_map.cpp

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
