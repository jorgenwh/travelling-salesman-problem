#include "cities.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

static std::random_device rd;
static std::mt19937 gen(rd());

int randint(int min, int max) {
    using distribution_type = std::uniform_int_distribution<int>;
    using param_type = typename distribution_type::param_type;

    thread_local distribution_type dist;
    return dist(gen, param_type(min, max));
}

int main(int argc, char** argv) {
    std::string filename = "../european_cities.csv"; //argv[1];
    Cities cities(filename);
    
    auto city_vec = cities.get_cities();
    int num_passes = 1000000;

    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::duration<float, std::milli> duration;

    double total_time = 0;
    auto t1 = clock::now();

    for (int i = 0; i < num_passes; i++) {
        int ran = randint(0, i);
    }

    auto t2 = clock::now();
    duration elapsed = t2 - t1;
    total_time += elapsed.count();

    std::cout << "total time elapsed: " << total_time << "ms ~ " << total_time / num_passes << "ms/pass" << std::endl;
}

