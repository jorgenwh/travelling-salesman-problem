#pragma once

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <string>

namespace TSP {

extern std::vector<std::string> cities_;
extern std::vector<float> distances_;
extern std::unordered_map<std::string, int> index_map_;

void initialize_city_data(std::string &filename);
std::vector<std::string> get_cities();
float distance(std::string &c1, std::string &c2);
float evaluate(std::vector<std::string> &permutation);

} // TSP
