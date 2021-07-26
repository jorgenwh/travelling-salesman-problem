#pragma once

#include "genetic.h"
#include "cities.h"

#include <vector>
#include <string>
#include <thread>
#include <mutex>

namespace TSP {
namespace genetic {

std::vector<solution> weighted_selection(std::vector<solution> &population, unsigned num);

class Optimizer {
public:
    Optimizer() = default;
    solution optimize(
            unsigned population_size,
            float mutation_rate,
            unsigned generations);
private:
    solution best_solution_(std::numeric_limits<float>::max());
    std::vector<solution> population_;

    unsigned solution_cntr_ = 0;
    std::mutex next_solution_mu_;
    std::mutex update_solution_mu_;
    
    solution &get_next_solution_();
    void update_best_solution_(solution &new_solution);
};

} // genetic
} // TSP
