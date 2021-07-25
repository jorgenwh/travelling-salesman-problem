#include "cities.h"
#include "genetic.h"

#include <vector>
#include <string>
#include <iostream>
#include <chrono>

void print_vec(std::vector<std::string> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl << std::endl;
}

int main(int argc, char **argv) {
    std::string filename = "../european_cities.csv";//argv[1];
    int num_cities = 10;//std::stoi(argv[2]);
    int num_threads = 1;//std::stoi(argv[3]);

    TSP::initialize_city_data(filename);
    
    auto cities = TSP::get_cities();
    std::cout << "original cities:" << std::endl;
    print_vec(cities);

    TSP::genetic::solution solution(cities);
    print_vec(solution.permutation_);

    cities[1] = "LOL";

    print_vec(solution.permutation_);

    print_vec(cities);

}
