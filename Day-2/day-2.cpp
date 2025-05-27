#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

bool is_safe(const std::vector<int>& levels){
    bool increasing{true};
    bool decreasing{true};

    for(size_t i = 1; i < levels.size(); i++){
        if(levels[i] > levels[i-1]){
                decreasing = false;
        }
        else if(levels[i] < levels[i-1]){
                increasing = false;
        }
        else{
            decreasing = false;
            increasing = false;
        }
    } 

    bool gradual{true};
    for(size_t i = 1; i < levels.size(); i++){
        if(std::abs(levels[i] - levels[i-1]) < 1 || std::abs(levels[i] - levels[i-1]) > 3){
                gradual = false;
        }
    }

    if((increasing || decreasing) && gradual) return true;
    else return false;
}

bool has_one_unsafe_level(const std::vector<int>& levels){
    for(size_t i = 0; i < levels.size(); i++){
        std::vector<int> new_levels;
        for(size_t j = 0; j < levels.size(); j++){
            if(j != i) new_levels.push_back(levels[j]);
        }
        if(is_safe(new_levels)) return true;
    }
    return false;
}

int main(int argc, char** argv){
    std::string input_file = argv[1];
    std::ifstream file(input_file);
    std::string line;

    size_t count{0};

    while(std::getline(file, line)){
        std::istringstream iss(line);
        int temp{0};
        std::vector<int> levels;

        while(iss >> temp){
            levels.push_back(temp);
        }

        if(is_safe(levels)){
            count++;
        }
        else{
            if(has_one_unsafe_level(levels)){
                count++;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}