#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

int main(int argc, char** argv) {
    std::ifstream file(argv[1]);
    std::ostringstream oss;
    oss << file.rdbuf();
    std::string data = oss.str();

    std::regex pattern(R"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))");

    std::sregex_iterator begin(data.begin(), data.end(), pattern);
    std::sregex_iterator end;

    bool executing = true;
    long long result = 0;

    for (auto it = begin; it != end; ++it) {
        std::smatch match = *it;
        std::string token = match.str();

        if (token == "do()") {
            executing = true;
        } 
        else if (token == "don't()") {
            executing = false;
        } 
        else{
            if(executing){
                int x = std::stoi(match[1].str());
                int y = std::stoi(match[2].str());
                result += x * y;
            }
        }
    }

    std::cout << result << "\n";
    return 0;
}
