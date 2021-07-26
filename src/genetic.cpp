#include "genetic.h"
#include "cities.h"

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <random>
#include <iostream>

namespace TSP {
namespace genetic {

std::vector<solution> initialize_random_solutions(int population_size) {
    std::vector<solution> population(population_size);
    for (int i = 0; i < population_size; i++) {
        std::vector<std::string> permutation = TSP::get_cities();
        std::shuffle(permutation.begin(), permutation.end(), rnd_engine);
        solution s(permutation);
        population[i] = s;
    }
    return population;
}

void solution::print() const {
    for (int i = 0; i < permutation_.size(); i++) {
        std::cout << permutation_[i];
        if (i < permutation_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int randint(int min, int max) {
    using distribution_type = std::uniform_int_distribution<int>;
    using param_type = typename distribution_type::param_type;
    thread_local distribution_type dist;
    return dist(gen, param_type(min, max));
}

namespace crossover {

std::vector<std::string> roll_crossover(std::vector<std::string> &genome1, std::vector<std::string> &genome2) {
    int length = genome1.size();
    int filled = 0;
    std::vector<std::string> child(length);

    // determine the segment that we copy directly from genome1
    int idx1 = randint(0, length - 1);
    int idx2 = randint(0, length - 1);
    if (idx1 > idx2) {
        std::swap(idx1, idx2);
    }
    for (int i = idx1; i < idx2; i++) {
        child[filled] = genome1[i];
        filled ++;
    }

    // roll whatever elements haven't been copied into the child from genome2
    for (int i = 0; i < length; i++) {
        // if the current element we are iterating over in genome2 isn't in the child
        if (std::find(child.begin(), child.end(), genome2[i]) == child.end()) {
            child[filled] = genome2[i];
            filled ++;
        }
        if (filled == length) {
            break;
        }
    }
    return child;
}

} // crossover

namespace mutate {


std::vector<std::string> &swap_mutate(std::vector<std::string> &genome) {
    int idx1 = randint(0, genome.size() - 1);
    int idx2 = randint(0, genome.size() - 1);
    std::swap(genome[idx1], genome[idx2]);
    return genome;
}

std::vector<std::string> &shuffle_mutate(std::vector<std::string> &genome) {
    int idx1 = randint(0, genome.size() - 1);
    int idx2 = randint(0, genome.size() - 1);
    if (idx1 > idx2) {
        std::swap(idx1, idx2);
    }
    std::shuffle(genome.begin() + idx1, genome.begin() + idx2, rnd_engine);
    return genome;
}

std::vector<std::string> &inversion_mutate(std::vector<std::string> &genome) {
    int idx1 = randint(0, genome.size() - 1);
    int idx2 = randint(0, genome.size() - 1);
    if (idx1 > idx2) {
        std::swap(idx1, idx2);
    }
    std::reverse(genome.begin() + idx1, genome.begin() + idx2);
    return genome;
}

} // mutate
} // genetic
} // TSP
