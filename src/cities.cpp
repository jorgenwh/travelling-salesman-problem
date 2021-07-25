#include "cities.h"

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <string>

namespace TSP {

std::vector<std::string> cities_;
std::vector<float> distances_;
std::unordered_map<std::string, int> index_map_;

// get a copy of the city vector 
std::vector<std::string> get_cities() {
    std::vector<std::string> cities = cities_;
    return cities;
}

// read city data from file
void initialize_city_data(std::string &filename) {
    std::string line;
    std::ifstream f(filename);

    if (f.is_open()) {
        while (getline(f, line)) {
            std::stringstream strm(line);
            std::string segment;
            if (cities_.size() == 0) {
                while (std::getline(strm, segment, ';')) {
                    cities_.push_back(segment);
                    index_map_[segment] = cities_.size() - 1;
                }
            }
            else {
                while (std::getline(strm, segment, ';')) {
                    distances_.push_back(std::stof(segment));
                }
            }
        }
        f.close();
    }
    else {
        std::cout << "Error: unable to open file: '" << filename << "'." << std::endl;
        exit(1);
    }
}

float distance(std::string &c1, std::string &c2) {
    return distances_[index_map_[c1] + (index_map_[c2] * cities_.size())];
}

float evaluate(std::vector<std::string> &permutation) {
     float total_distance = 0;
     for (int i = 0; i < permutation.size() - 1; i++) {
         total_distance += distance(permutation[i], permutation[i+1]);
     }
     total_distance += distance(permutation.back(), permutation[0]);
     return total_distance;
}
} // TSP
