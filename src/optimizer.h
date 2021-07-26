#pragma once

#include "genetic.h"
#include "cities.h"

#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <thread>
#include <mutex>
#include <limits>

namespace TSP {
namespace genetic {

class Optimizer {
public:
    Optimizer() = default;
    Optimizer(
            unsigned population_size,
            float mutation_rate,
            unsigned generations,
            unsigned num_threads) :
        population_size_(population_size), 
        mutation_rate_(mutation_rate), 
        generations_(generations), 
        num_threads_(num_threads) 
    {}
    solution optimize();
private:
    unsigned population_size_ = 500;
    float mutation_rate_ = 0.25;
    unsigned generations_ = 1000;
    unsigned num_threads_ = 4;
    solution best_solution_;

    std::vector<solution> population_;
    std::vector<solution> parents_;
    std::vector<solution> children_;

    unsigned child_cntr_ = 0;
    std::mutex next_child_mu_;

    unsigned solution_cntr_ = 0;
    std::mutex next_solution_mu_;
    
    void evaluate_all_solutions_();
    void evaluate_solutions_();
    int get_next_solution_index_();

    void create_all_children_();
    void create_children_();
    int get_next_child_index_(); 

    void weighted_selection_(unsigned num);
    };

} // genetic
} // TSP
