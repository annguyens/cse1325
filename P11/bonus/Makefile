CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main 

debugger: CXXFLAGS += -g
debugger: main

main: main.o 
	$(CXX) $(CXXFLAGS) main.o -o words

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch ~* a.out main words
