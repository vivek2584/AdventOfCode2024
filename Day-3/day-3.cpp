#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

int main(int argc, char** argv){
    std::ifstream file(argv[1]);
    std::ostringstream oss;
    oss << file.rdbuf();
    std::string data = oss.str();

    std::regex pattern(R"(mul\((\d+),(\d+)\))");

    std::sregex_iterator begin(data.begin(), data.end(), pattern);
    std::sregex_iterator end;

    int result{0};

    for(auto it = begin; it != end ; ++it){

        std::smatch match = *it;
        int num1 = std::stoi(match[1].str());
        int num2 = std::stoi(match[2].str());
        
        result += num1 * num2;
    }

    std::cout << result << "\n";
    return 0;
}