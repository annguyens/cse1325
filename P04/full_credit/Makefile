CXXFLAGS = --std=c++17

all: coin test main

logger: CXXFLAGS += -DLOGGER
logger: coin

rebuild: clean logger

coin: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin
test: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o test
main: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o main

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
color.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o

coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h coin.gch

clean:
	rm -f *.o *.gch ~* a.out test coin main

