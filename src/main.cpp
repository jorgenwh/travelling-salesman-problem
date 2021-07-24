#include "cities.h"
#include "genetic.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

int main(int argc, char **argv) {
    std::string filename = "../european_cities.csv";//argv[1];
    int num_cities = 10;//std::stoi(argv[2]);
    int num_threads = 1;//std::stoi(argv[3]);

    TSP::Cities cities(filename);

    auto all_cities_vec = cities.get_cities();
    std::vector<std::string> city_vec(num_cities);
    for (int i = 0; i < num_cities; i++) {
        city_vec[i] = all_cities_vec[i];
    }

    
}
