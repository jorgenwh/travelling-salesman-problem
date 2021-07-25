#include "cities.h"
#include "genetic.h"
#include "optimize.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

int main(int argc, char **argv) {
    std::string filename = "../european_cities.csv";
    TSP::initialize_city_data(filename);

    int population_size = std::stoi(argv[1]);
    float mutation_rate = std::stof(argv[2]);
    int generations = std::stoi(argv[3]);

    auto t1 = std::chrono::steady_clock::now();
    auto solution = TSP::genetic::optimize(population_size, mutation_rate, generations);
    auto t2 = std::chrono::steady_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    std::cout << "Settings: [population_size: " << population_size << ", mutation_rate: " << mutation_rate << ", generations: " << generations << "]" << std::endl;
    std::cout << "Compute time: " << delta << " milliseconds" << std::endl;
    std::cout << "Shortest distance found: " << solution.distance_ << " - with the solution:" << std::endl;
    solution.print();
}
