#pragma once

#include "cities.h"

#include <limits>
#include <iterator>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

namespace TSP {
namespace genetic {

struct solution {
    solution() = default;
    solution(float dist) : distance_(dist) {}
    solution(std::vector<std::string> &permutation) : permutation_(permutation) {}
    void evaluate() {
        if (distance_ == -1) {
            distance_ = TSP::evaluate(permutation_);
        }
    }
    void print() const;
    bool operator<(const solution &other) const {
        return distance_ < other.distance_;
    }

    std::vector<std::string> permutation_;
    float distance_ = -1;
};

std::vector<solution> initialize_random_solutions(int population_size);

static std::random_device rd;
static std::mt19937_64 gen(rd());
static std::default_random_engine rnd_engine = std::default_random_engine {};

int randint(int min, int max);

namespace crossover {
std::vector<std::string> pmx(std::vector<std::string> &genome1, std::vector<std::string> &genome2);
} // crossover

namespace mutate {
std::vector<std::string> &swap_mutate(std::vector<std::string> &genome);
std::vector<std::string> &shuffle_mutate(std::vector<std::string> &genome);
std::vector<std::string> &inversion_mutate(std::vector<std::string> &genome);
} // mutate
} // genetic
} // TSP
