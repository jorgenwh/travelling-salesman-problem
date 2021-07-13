#pragma once

#include <string>
#include <unordered_map>
#include <vector>   
#include <fstream>

class CityData {
    public:
        CityData(std::string& filename) {
            read_city_file(filename);
        }

        float distance(std::string& city1, std::string& city2) {
            int row = index_map[city1];
            int col = index_map[city2];
            float distance = distances[row + (col * cities.size())];
            return distance;
        }

    private:
        std::unordered_map<std::string, int> index_map;
        std::vector<std::string> cities;
        std::vector<float> distances;

        void read_city_file(std::string& filename);
};
