CXX = g++
CXXFLAGS = -std=c++17 -O3 -pthread
CPPFLAGS =

obj = build/main.o build/cities.o build/genetic.o build/optimizer.o 
headers = cities.h genetic.h optimizer.h

prog: $(obj)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(obj) -o prog

build/main.o: main.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c main.cpp -o build/main.o

build/cities.o: cities.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c cities.cpp -o build/cities.o

build/genetic.o: genetic.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c genetic.cpp -o build/genetic.o

build/optimizer.o: optimizer.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c optimizer.cpp -o build/optimizer.o

.PHONY: clean
clean:
	rm build/*.o
	rm prog
