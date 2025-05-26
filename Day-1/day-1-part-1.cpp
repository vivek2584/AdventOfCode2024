#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char** argv){
    std::string input_file = argv[1];
    std::ifstream file(input_file);
    std::string line;

    std::vector<int> list_1;
    std::vector<int> list_2;

    while(std::getline(file, line)){
        std::istringstream iss(line);
        int a, b;
        iss >> a >> b;
        list_1.push_back(a);
        list_2.push_back(b);
    }
    
    std::sort(list_1.begin(), list_1.end());
    std::sort(list_2.begin(), list_2.end());

    int total_distance{0};

    for(size_t i = 0; i < list_1.size(); i++){
        total_distance += std::abs(list_1[i] - list_2[i]);
    }

    std::cout << total_distance << "\n";

    return 0;
}