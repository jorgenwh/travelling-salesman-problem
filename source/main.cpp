#include "cities.h"
#include "genetic.h"
#include "optimize.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>

int main(int argc, char** argv) {
    std::string filename = "../european_cities.csv"; 

    Cities cities(filename);
    int population_size = 30;
    float mutation_rate = 0.15;
    int generations = 10;

    auto solution = genetic::optimize(cities, population_size, mutation_rate, generations);

    std::cout << "Shortest distance found: " << solution.distance << std::endl;
    std::cout << "with the solution:" << std::endl;
    for (int i = 0; i < solution.permutation.size(); i++) {
        std::cout << solution.permutation[i];
        if (i != solution.permutation.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

