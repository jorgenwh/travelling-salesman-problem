#pragma once

namespace genetic {

class Solution {
public:
    Solution() = default;
    Solution(std::vector<std::string>& perm) : permutation(perm) {}
    
    std::vector<std::string> permutation;
    float distance = -1;
};

Solution optimize(
        Cities& cities,
        int population_size,
        float mutation_rate,
        int generations
        );

} // genetic
