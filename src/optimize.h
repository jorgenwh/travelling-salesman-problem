#pragma once

#include "genetic.h"
#include "cities.h"

#include <vector>
#include <string>

namespace TSP {
namespace genetic {

std::vector<solution> weighted_selection(std::vector<solution> &population, unsigned num);

solution optimize(
        unsigned population_size,
        float mutation_rate,
        unsigned generations);

} // genetic
} // TSP
