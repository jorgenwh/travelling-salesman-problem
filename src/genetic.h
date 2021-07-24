#pragma once

#include <limits>
#include <iterator>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

namespace TSP {
namespace genetic {

static std::random_device rd;
static std::mt19937 gen(rd());

int randint(int min, int max);

namespace crossover {
std::vector<std::string> pmx(std::vector<std::string> &genome1, std::vector<std::string> &genome2);
} // crossover

namespace mutate {
std::vector<std::string> &swap_mutate(std::vector<std::string> &genome);
std::vector<std::string> &shuffle_mutate(std::vector<std::string> &genome);
std::vector<std::string> &inversion_mutate(std::vector<std::string> &genome);
} // mutate
} // genetic
} // TSP
