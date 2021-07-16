#include "cities.h"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <limits>

std::mutex next_permutation_mu;
std::mutex update_best_solution_mu;

void update_best_solution(
        float &best_distance, 
        std::vector<std::string> &best_permutation, 
        float &new_best_distance,
        std::vector<std::string> &new_best_permutation
        ) {
    std::lock_guard<std::mutex> guard(update_best_solution_mu);
    best_distance = new_best_distance;
    best_permutation = new_best_permutation;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "invalid number of arguments: expected 2: [filename] [num_cities]" << std::endl;
        exit(1);
    }

    std::string filename = argv[1]; 
    int num_cities = std::stoi(argv[2]);

    Cities cities(filename);
    auto city_vec = cities.get_cities();
    std::vector<std::string> permutation(num_cities);

    // copy the cities we are interested in
    for (int i = 0; i < num_cities; i++) {
        permutation[i] = city_vec[i];
    }

    // keep track of best solution found so far
    float best_distance = std::numeric_limits<float>::max();
    std::vector<std::string> best_permutation;

    // start the exhaustive search
    auto t1 = std::chrono::steady_clock::now();

    // for each permutation of the city list
    do {
        float distance = cities.evaluate(permutation);
        if (distance < best_distance) {
            update_best_solution(best_distance, best_permutation, distance, nullptr) // TODO
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    auto t2 = std::chrono::steady_clock::now();

    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms" << std::endl;
    std::cout << "shortest distance found: " << best_distance << " with the solution:" << std::endl;
    for (auto city: best_permutation)
        std::cout << city << ", ";
    std::cout << std::endl;
}

