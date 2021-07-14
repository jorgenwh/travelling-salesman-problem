#include "solution.h"
#include "cities.h"

#include <limits>
#include <string>
#include <vector>
#include <limits>

namespace genetic {

Solution* genetically_optimize(
        Cities cities, 
        int population_size, 
        float mutation_rate,
        int generations);

namespace crossover {
std::vector<std::string> pmx(std::vector<std::string>& genome1, std::vector<std::string>& genome2);
} // crossover

namespace mutate {
void swap_mutate(std::vector<std::string>& genome);
void shuffle_mutate(std::vector<std::string>& genome);
void inversion_mutate(std::vector<std::string>& genome);
} // mutate
} // genetic
