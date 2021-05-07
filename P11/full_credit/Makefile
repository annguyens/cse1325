CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main 

debugger: CXXFLAGS += -g
debugger: main

main: main.o cart.o item.o *.h
	$(CXX) $(CXXFLAGS) main.o cart.o item.o -o cart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) cart.cpp -c -o cart.o

item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) item.cpp -c -o item.o

clean:
	rm -f *.o *.gch ~* a.out cart item main

