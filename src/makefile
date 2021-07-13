CXX = g++
CXXFLAGS = -std=c++17 -O2
CPPFLAGS =

obj = build/main.o build/cities.o build/genetic.o
headers = cities.h genetic.h solution.h 

prog: $(obj)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(obj) -o prog

build/main.o: main.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c main.cpp -o build/main.o

build/cities.o: cities.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c cities.cpp -o build/cities.o

build/genetic.o: genetic.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c genetic.cpp -o build/genetic.o

.PHONY: clean
clean:
	rm build/*.o
	rm prog
