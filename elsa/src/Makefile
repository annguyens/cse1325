CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main 

debugger: CXXFLAGS += -g
debugger: main


main: main.o options.o desktop.o order.o customer.o store.o  mainwin.o entrydialog.o *.h
	$(CXX) $(CXXFLAGS) main.o options.o store.o desktop.o order.o customer.o mainwin.cpp entrydialog.cpp $(GTKFLAGS) -o store

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c $(GTKFLAGS) -o main.o

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

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) mainwin.cpp -c $(GTKFLAGS) -o mainwin.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) entrydialog.cpp -c $(GTKFLAGS) -o entrydialog.o

clean:
	rm -f *.o *.gch ~* a.out main options store desktop order customer mainwin entrydialog
