CXXFLAGS = --std=c++17

all: main 

debugger: CXXFLAGS += -g
debugger: product


main: main.o options.o desktop.o order.o customer.o store.o *.h
	$(CXX) $(CXXFLAGS) main.o options.o store.o desktop.o order.o customer.o -o store

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) options.cpp -c -o options.o

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) desktop.cpp -c -o desktop.o

order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) order.cpp -c -o order.o

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) customer.cpp -c -o customer.o

store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) store.cpp -c -o store.o

clean:
	rm -f *.o *.gch ~* a.out main options store desktop order customer
