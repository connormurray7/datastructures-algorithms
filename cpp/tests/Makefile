CXX        = clang++
SOURCES    = $(wildcard *.cpp)
OBJECTS    = $(SOURCES:%.cpp=%.o)
EXECUTABLE = main
VALGRIND   = valgrind --leak-check=yes
CXXFLAGS   = -std=c++14 -stdlib=libc++ -Wall -Werror -Wextra -pedantic

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

test_vector.o: test_vector.cpp
test_binary_tree.o: test_binary_heap.cpp
test_binary_heap.o: test_binary_tree.cpp
test_hash_set.o: test_hash_set.cpp
test_hash_map.o: test_hash_map.cpp
test_trie.o: test_trie.cpp
test_graph.o: test_graph.cpp
test_bfs.o: test_bfs.cpp
test_top_sort.o: test_top_sort.cpp

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
