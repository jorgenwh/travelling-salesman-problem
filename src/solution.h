#pragma once

#include <iostream>
#include <vector>
#include <string>

// struct to represent a single solution
struct Solution {
    Solution(std::vector<std::string>& perm) : permutation(perm) {}

    void pretty() const {
        for (std::string city: permutation)
            std::cout << city << " -> ";
        std::cout << std::endl;
    }

    std::vector<std::string> permutation;
    float distance = -1;

    bool operator>(Solution& other) const { return (distance > other.distance); }
    bool operator<(Solution& other) const { return (distance < other.distance); }
    bool operator>=(Solution& other) const { return (distance >= other.distance); }
    bool operator<=(Solution& other) const { return (distance <= other.distance); }
    bool operator==(Solution& other) const { return (distance == other.distance); }
};
