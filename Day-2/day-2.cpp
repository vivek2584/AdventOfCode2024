#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char** argv){
    // part-1 START
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

        if((increasing || decreasing) && gradual) count++;
    }

    std::cout << count << "\n";

    return 0;
}