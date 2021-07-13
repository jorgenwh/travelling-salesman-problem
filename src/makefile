CXX = g++
CXXFLAGS = -std=c++17 -O2
CPPFLAGS =

obj = build/main.o build/city_data.o
headers = city_data.h genetic.h solution.h 

prog: $(obj)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(obj) -o prog

build/main.o: main.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c main.cpp -o build/main.o

build/city_data.o: city_data.cpp $(headers)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c city_data.cpp -o build/city_data.o

.PHONY: clean
clean:
	rm build/*.o
	rm prog
