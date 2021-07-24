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

    TSP::initialize_city_data(filename);
    auto cities = TSP::get_cities();

    std::cout << cities.size() << std::endl;
    for (auto x: cities)
        std::cout << x << std::endl;
}
