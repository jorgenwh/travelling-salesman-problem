#include "solution.h"
#include "cities.h"

#include <string>
#include <vector>

namespace genetic {

// store result data from optimization algorithm
struct Data {
    Data(std::vector<std::string>& perm, float& dist) : shortest_permutation(perm), shortest_distance(dist) {}
    std::vector<std::string> shortest_permutation;
    float shortest_distance;
};

namespace crossover {
std::vector<std::string> pmx(std::vector<std::string>& genome1, std::vector<std::string>& genome2);
} // crossover


namespace mutate {
void swap_mutate(std::vector<std::string>& genome);
void shuffle_mutate(std::vector<std::string>& genome);
void inversion_mutate(std::vector<std::string>& genome);
} // mutate

} // genetic
