#include "optimize.h"
#include "genetic.h"
#include "cities.h"

#include <random>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

namespace genetic {

std::vector<Solution> initialize_population(Cities& cities, int size) {
    auto r_engine = std::default_random_engine {};
    std::vector<Solution> population(size);
    for (int i = 0; i < size; i++) {
        auto permutation = cities.get_cities();
        std::shuffle(permutation.begin(), permutation.end(), r_engine);
        Solution solution(permutation);
        solution.distance = cities.evaluate(solution.permutation);
    }
    return population;
}

Solution optimize(
        Cities& cities,
        int population_size,
        float mutation_rate,
        int generations
        ) {
    // initialize a random population
    auto population = initialize_population(cities, population_size);
    
    return population[0];

}

} // genetic
