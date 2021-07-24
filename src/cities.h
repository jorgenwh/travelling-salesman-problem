#pragma once

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <string>

namespace TSP {

extern std::vector<std::string> cities;
extern std::vector<float> distances;
extern std::unordered_map<std::string, int> index_map;

void initialize_city_data(std::string &filename);
float distance(std::string &c1, std::string &c2) {
    return distances[index_map[c1] + (index_map[c2] * cities.size())];
}
static float evaluate(std::vector<std::string> &permutation);

} // TSP
