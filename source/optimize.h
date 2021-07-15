#pragma once

#include "genetic.h"
#include "cities.h"

#include <vector>
#include <string>
#include <random>
#include <algorithm>

namespace genetic {

class Solution {
public:
    Solution() = default;
    Solution(std::vector<std::string>& perm) : permutation(perm) {}
    
    std::vector<std::string> permutation;
    float distance = -1;
};

std::vector<Solution> initialize_population(Cities& cities, int size);

Solution optimize(
        Cities& cities,
        int population_size,
        float mutation_rate,
        int generations
        );

} // genetic