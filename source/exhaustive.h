#pragma once

#include <vector>
#include <string>
#include <thread>
#include <mutex>

namespace TSP {

class Exhaustive {
public:
    Exhaustive(const std::vector<std::string> &cities, const int num_threads)
        : permutation(cities), num_theads(num_theads) {}

    // start searching for the best permutation
    void start_search();

    // get data representing the best found solution
    std::vector<std::string> get_best_permutation() const { return best_permutation; }
    float get_best_distance() const { return best_distance; }

private:
    // the current permutation and thread count
    std::vector<std::string> permutation;
    const int num_theads;

    // thread mutices
    std::mutex next_permutation_mu;
    std::mutex update_best_permutation_mu;
    bool done = false;

    // data storing the best solution found so far
    std::vector<std::string> best_permutation;
    float best_distance;

    // search through permutations
    void search();

    // get the next permutation
    std::vector<std::string> &next_permutation();

    // update the best found solution
    void update_best_permutation(const std::vector<std::string> &permutation, const float &distance);

}; // Exhaustive

} // TSP
