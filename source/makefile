CXX = g++
CXXFLAGS = -std=c++17 -O2
CPPFLAGS =

obj = build/main.o build/cities.o 
headers = cities.h 

prog: $(obj)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(obj) -o prog

build/main.o: main.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c main.cpp -o build/main.o

build/cities.o: cities.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c cities.cpp -o build/cities.o

.PHONY: clean
clean:
	rm build/*.o
	rm prog
