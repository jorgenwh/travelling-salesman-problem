#pragma once

#include <iostream>
#include <vector>
#include <string>

// class to represent a single solution
class Solution {
    public:
        Solution(std::vector<std::string>& perm) : permutation(perm) {}

        void pretty() const {
            for (std::string city: permutation)
                std::cout << city << " -> ";
            std::cout << std::endl;
        }

    private:
        std::vector<std::string> permutation;
        float distance = -1;
};
