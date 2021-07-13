#pragma once

// class to represent a single solution
class Solution {
    public:
        Solution(std::vector<std::string>& permutation) : permutation(permutation) {}

        void pretty() const {
            for (auto city: permutation)
                std::cout << city << " -> ";
            std::cout << std::endl;
        }

    private:
        std::vector<std::string> permutation;
        float distance = -1;
};
