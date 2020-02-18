CXXFLAGS = --std=c++17

all: coin test 

logger: CXXFLAGS += -DLOGGER
logger: coin

rebuild: clean logger

coin: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin
test: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o test

coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h coin.gch

clean:
	rm -f *.o *.gch ~* a.out test coin 

