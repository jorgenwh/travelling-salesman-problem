CXX = g++
CXXFLAGS = -std=c++17 -O2
CPPFLAGS =

obj = build/main.o build/cities.o build/genetic.o build/optimize.o
headers = cities.h genetic.h optimize.h

prog: $(obj)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(obj) -o prog

build/main.o: main.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c main.cpp -o build/main.o

build/cities.o: cities.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c cities.cpp -o build/cities.o

build/genetic.o: genetic.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c genetic.cpp -o build/genetic.o

build/optimize.o: optimize.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c optimize.cpp -o build/optimize.o

.PHONY: clean
clean:
	rm build/*.o
	rm prog
