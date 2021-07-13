#include "city_data.h"
#include "genetic.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main(int argc, char** argv) {
    std::string filename = argv[1];
    CityData city_data(filename);

    float a = 1;
    auto two = Genetic::add_one(a);
    std::cout << two << std::endl;
}
