#include "genetic.h"
#include "cities.h"

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

namespace genetic {

int randint(int min, int max) {
    using distribution_type = std::uniform_int_distribution<int>;
    using param_type = typename distribution_type::param_type;
    thread_local distribution_type dist;
    return dist(gen, param_type(min, max));
}

namespace crossover {

std::vector<std::string> pmx(std::vector<std::string>& genome1, std::vector<std::string>& genome2) {
    int length = genome1.size();

    // determine the segment that we copy from genome1 into the child
    int idx1 = randint(0, length - 1);
    int idx2 = randint(0, length - 1);
    if (idx1 > idx2)
        std::swap(idx1, idx2);

    // start building the child genome by copying the determined segment from genome1
    std::vector<std::string> child(length);
    for (int i = idx1; i < idx2; i++)
        child[i] = genome1[i];

    // look through the determined segment and find all elements in genome2 that weren't copied to the child
    for (int i = idx1; i < idx2; i++) {
        int ind = i;
        // check if child contains x
        if (std::find(child.begin(), child.end(), genome2[ind]) == child.end()) {
            while (child[ind] != "") {
                auto g1_elem = genome1[ind];
                
                // find the index of the genome1 element in genome2
                auto it = std::find(genome2.begin(), genome2.end(), g1_elem);
                int pos = it - genome2.begin();
                ind = pos;
            }
            child[ind] = genome2[i];
        }
    }

    // fill any remaining empty slots in the child genome from genome2
    for (int i = 0; i < length; i++) {
        if (child[i] == "")
            child[i] = genome2[i];
    }

    return child;
}
} // crossover

namespace mutate {

auto rnd_engine = std::default_random_engine {};

void swap_mutate(std::vector<std::string>& genome) {
    int idx1 = randint(0, genome.size() - 1);
    int idx2 = randint(0, genome.size() - 1);
    std::swap(genome[idx1], genome[idx2]);
}

void shuffle_mutate(std::vector<std::string>& genome) {
    int idx1 = randint(0, genome.size() - 1);
    int idx2 = randint(0, genome.size() - 1);
    if (idx1 > idx2)
        std::swap(idx1, idx2);

    std::shuffle(genome.begin() + idx1, genome.begin() + idx2, rnd_engine);
}

void inversion_mutate(std::vector<std::string>& genome) {
    int idx1 = randint(0, genome.size() - 1);
    int idx2 = randint(0, genome.size() - 1);
    if (idx1 > idx2)
        std::swap(idx1, idx2);
    
    std::reverse(genome.begin() + idx1, genome.begin() + idx2);
}

} // mutate
} // genetic
