#include "exhaustive.h"

#include <vector>
#include <string>
#include <thread>
#include <mutex>

namespace TSP {

Exhaustive::start_search() {

    // create and start the threads
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; i++) {
        threads.push_back(std::thread(&Exhaustive::search, this));
    }

}



} // TSP
