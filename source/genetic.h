#pragma once

#include <limits>
#include <iterator>
#include <string>
#include <vector>
#include <limits>
#include <random>

namespace genetic {

static std::random_device rd;
static std::mt19937 gen(rd());

int randint(int min, int max);

namespace crossover {
std::vector<std::string> pmx(std::vector<std::string>& genome1, std::vector<std::string>& genome2);
} // crossover

namespace mutate {
void swap_mutate(std::vector<std::string>& genome);
void shuffle_mutate(std::vector<std::string>& genome);
void inversion_mutate(std::vector<std::string>& genome);
} // mutate
} // genetic
