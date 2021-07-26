#include "genetic.h"
#include "cities.h"
#include "optimizer.h"

#include <random>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <thread>
#include <mutex>

namespace TSP {
namespace genetic {

int Optimizer::get_next_solution_index_() {
    std::lock_guard<std::mutex> lock(next_solution_mu_);
    solution_cntr_ ++;
    return solution_cntr_ - 1;
}

void Optimizer::evaluate_solutions_() {
    while (true) {
        int i = get_next_solution_index_();
        if (i >= population_.size()) {
            break;
        }
        population_[i].evaluate();
    }
}

void Optimizer::evaluate_all_solutions_() {
    solution_cntr_ = 0;
    std::vector<std::thread> threads(num_threads_);
    for (int i = 0; i < num_threads_; i++) {
        threads[i] = std::thread(&Optimizer::evaluate_solutions_, this);
    }
    for (int i = 0; i < num_threads_; i++) {
        if (threads[i].joinable()) {
            threads[i].join();
        }
    }
}

int Optimizer::get_next_child_index_() {
    std::lock_guard<std::mutex> lock(next_child_mu_);
    child_cntr_ ++;
    return child_cntr_ - 1;
}

void Optimizer::create_children_() {
    while (true) {
        int i = get_next_child_index_();
        if (i >= children_.size()) {
            break;
        }
        
        // randomly select parents
        solution &p1 = parents_[randint(0, parents_.size() - 1)];
        solution &p2 = parents_[randint(0, parents_.size() - 1)];
        std::vector<std::string> child_permutation = crossover::roll_crossover(p1.permutation_, p2.permutation_);

        // roll whether or not to mutate this child
        if (randfloat(0, 1) <= mutation_rate_) {
            // apply a random mutation
            auto roll = randint(0, 2);
            switch (roll) {
                case 0:
                    child_permutation = mutate::swap_mutate(child_permutation);
                    break;
                case 1:
                    child_permutation = mutate::shuffle_mutate(child_permutation);
                    break;
                case 2:
                    child_permutation = mutate::inversion_mutate(child_permutation);
                    break;
                default:
                    std::cout << "Error: invalid mutation roll." << std::endl;
                    exit(1);
            }
        }
        
        // place the new child in the child vector
        children_[i] = solution(child_permutation);
    }
}

void Optimizer::create_all_children_() {
    child_cntr_ = 0;
    std::vector<std::thread> threads(num_threads_);
    for (int i = 0; i < num_threads_; i++) {
        threads[i] = std::thread(&Optimizer::create_children_, this);
    }
    for (int i = 0; i < num_threads_; i++) {
        if (threads[i].joinable()) {
            threads[i].join();
        }
    }
}

void Optimizer::weighted_selection_(unsigned num) {
    float max_fitness = 0;
    float mean_fitness = 0;
    for (auto const &sol: population_) {
        max_fitness = std::max(max_fitness, sol.distance_);
        mean_fitness += sol.distance_;
    }
    mean_fitness /= population_.size();

    std::vector<float> weights(population_.size());
    float sum_exps = 0;
    for (int i = 0; i < population_.size(); i++) {
        weights[i] = exp((-population_[i].distance_ + max_fitness) / mean_fitness);
        sum_exps += weights[i];
    }
    float sum_weights = 0;
    for (int i = 0; i < population_.size(); i++) {
        weights[i] /= sum_exps;
        sum_weights += weights[i];
    }

    for (int i = 0; i < num; i++) {
        float pick = randfloat(0, sum_weights);
        float cur = 0;
        for (int j = 0; j < population_.size(); j++) {
            cur += weights[j];
            if (cur > pick) {
                parents_[i] = population_[j];
                break;
            }
        }
    }
}

solution Optimizer::optimize() {
    best_solution_ = solution(std::numeric_limits<float>::max());
    parents_.resize((int) (population_size_ / 2));
    children_.resize(population_size_ - parents_.size());
    // initialize random population
    population_ = initialize_random_solutions(population_size_);
    // evaluate all solutions in population
    evaluate_all_solutions_();
    for (auto &sol: population_) {
        best_solution_ = std::min(best_solution_, sol);
    }
    // run generations
    for (int gen = 0; gen < generations_; gen++) {
        // select parents
        weighted_selection_((int) (population_size_ / 2));
        // create children
        create_all_children_();
        // add the new children to the population
        population_.insert(population_.end(), children_.begin(), children_.end());
        // evaluate the new population and update best found solution
        evaluate_all_solutions_();
        for (auto &sol: population_) {
            best_solution_ = std::min(best_solution_, sol);
        }
        // remove bad solutions until the correct population size is restored
        std::sort(population_.begin(), population_.end());
        int ete = population_.size() - population_size_;
        population_.erase(population_.end() - ete, population_.end());
    }    

    return best_solution_;
}

} // genetic
} // TSP
