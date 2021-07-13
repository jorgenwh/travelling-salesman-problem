#include "city_data.h"

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <string>

void CityData::read_city_file(std::string& filename) {
    std::string line;
    std::ifstream f(filename);

    if (f.is_open()) {
        while (getline(f, line)) {
            std::stringstream strm(line);
            std::string segment;
            if (cities.size() == 0) {
                while (std::getline(strm, segment, ';')) {
                    cities.push_back(segment);
                    index_map[segment] = cities.size() - 1;
                }
            }
            else {
                while (std::getline(strm, segment, ';')) {
                    float dist = std::stof(segment);
                    distances.push_back(dist);
                }
            }
        }
        f.close();
    }
    else {
        std::cout << "Error: unable to open file: '" << filename << "'." << std::endl;
        exit(1);
    }
}
