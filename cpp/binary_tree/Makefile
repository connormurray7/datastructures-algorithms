
# designate which compiler to use
CXX			= clang++ 
 # list of sources used in project
SOURCES 	= $(wildcard *.cpp)
 # list of objects used in project
OBJECTS		= $(SOURCES:%.cpp=%.o)
 # name of the executable produced by the top level
EXECUTABLE 	= main 

VALGRIND    = valgrind --leak-check=yes 

 #Default Flags
CXXFLAGS = -std=c++14 -stdlib=libc++ -Wall -Werror -Wextra -pedantic

# make release - will compile "all" with $(CXXFLAGS) and the -O3 flag
# 
release: CXXFLAGS += -O3 
release: all

# make debug - will compile "all" with $(CXXFLAGS) and the -g flag
#            
debug: CXXFLAGS += -g
debug: clean all

# make profile - will compile "all" with $(CXXFLAGS) and the -pg flag
profile: CXXFLAGS += -pg
profile: clean all

run: all 
run:
	./$(EXECUTEABLE)

# highest target; sews together all objects into executable
all: $(OBJECTS)
	 $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# individual dependencies for objects
C_Binary_Tree.o: C_Binary_Tree.cpp 

main.o: main.cpp

# rule for creating objects
%.o:
	 $(CXX) $(CXXFLAGS) -c $*.cpp

# make clean - remove .o files, executable 
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) 

valgrind: debug 
valgrind: 
	$(VALGRIND) ./$(EXECUTABLE)

# these targets do not create any files
.PHONY: all release debug profile clean valgrind
 	# disable built-in rules
.SUFFIXES:

