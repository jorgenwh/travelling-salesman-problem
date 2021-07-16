#include "cities.h"
#include "exhaustive.h"

#include <vector>
#include <string>

int main(int argc, char **argv) {
    std::string filename = "../european_cities.csv";
    Cities cities(filename);

    auto city_vec = cities.get_cities();
    TSP::Exhaustive search(city_vec, 1);
}
