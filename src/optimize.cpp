#include "genetic.h"
#include "cities.h"
#include "optimize.h"

#include <random>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

namespace TSP {
namespace genetic {

std::vector<solution> weighted_selection(std::vector<solution> &population, unsigned num) {
    float max_fitness = 0;
    float mean_fitness = 0;
    for (auto const &sol: population) {
        max_fitness = std::max(max_fitness, sol.distance_);
        mean_fitness += sol.distance_;
    }
    mean_fitness /= population.size();

    std::vector<float> weights(population.size());
    float sum_exps = 0;
    for (int i = 0; i < population.size(); i++) {
        weights[i] = exp((-population[i].distance_ + max_fitness) / mean_fitness);
        sum_exps += weights[i];
    }
    float sum_weights = 0;
    for (int i = 0; i < population.size(); i++) {
        weights[i] /= sum_exps;
        sum_weights += weights[i];
    }

    std::random_device rd_;
    std::default_random_engine rnd_engine_(rd_());
    std::uniform_real_distribution<> distr_(0, sum_weights);
    std::vector<solution> selected(num);
    for (int i = 0; i < num; i++) {
        float pick = distr_(rnd_engine_); 
        float cur = 0;
        for (int j = 0; j < population.size(); j++) {
            cur += weights[j];
            if (cur > pick) {
                selected[i] = population[j];
                break;
            }
        }
    }
    return selected;
}

solution optimize(
        unsigned population_size,
        float mutation_rate,
        unsigned generations) {

    solution best_solution(std::numeric_limits<float>::max());
    
    // initialize random population
    std::vector<solution> population = initialize_random_solutions(population_size);
    for (auto &solution: population) {
        solution.evaluate();
        if (solution.distance_ < best_solution.distance_) {
            best_solution = solution;
        }
    }

    // run generations
    for (int gen = 0; gen < generations; gen++) {
        // select parents
        std::vector<solution> parents = weighted_selection(population, (int ) (population_size / 2));

        std::random_device rd_;
        std::default_random_engine rnd_engine_(rd_());
        std::uniform_real_distribution<> distr_(0, 1);

        // create children
        auto num_children = population_size - parents.size();
        std::vector<solution> children(num_children);
        for (int i = 0; i < num_children; i++) {
            solution &p1 = parents[randint(0, parents.size() - 1)];
            solution &p2 = parents[randint(0, parents.size() - 1)];
            std::vector<std::string> child_permutation = crossover::pmx(p1.permutation_, p2.permutation_);

            // roll whether or not to mutate this child
            if (distr_(rnd_engine_) <= mutation_rate) {
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
            std::cout << 1 << std::endl;
            children[i] = solution(child_permutation);
            std::cout << 2 << std::endl;
        }
        
        // add the new children to the population
        population.insert(population.end(), children.begin(), children.end());

        // evaluate the new population and update best found solution
        for (auto &solution: population) {
            solution.evaluate();
            if (solution.distance_ < best_solution.distance_) {
                best_solution = solution;
            }
        }

        // remove bad solutions until the correct population size is restored
        std::sort(population.begin(), population.end());
        int ete = population.size() - population_size;
        population.erase(population.end() - ete, population.end());
    }    

    return best_solution;
}

} // genetic
} // TSP
