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

    // part-1 END

    // part-2 START

    std::unordered_map<int, int> count_map;

    for(int& i : list_2){
        count_map[i]++;
    }

    int similarity_score{0};

    for(int &i : list_1){
        similarity_score += i * count_map[i];
    }

    std::cout << similarity_score << "\n";
    
    // part-2 END

    return 0;
}