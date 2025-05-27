#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

size_t count_xmas(std::string& line){
    int count{0};
    int start{0};
    int end;
    while((end = line.find("XMAS", start)) != std::string::npos){
        start = end + 1;
        count++;
    }
    start = 0; end = 0;
    std::string rev = line;
    std::reverse(rev.begin(), rev.end());
    while((end = rev.find("XMAS", start)) != std::string::npos){
        start = end + 1;
        count++;
    }
    return count;
}

int main(int argc, char** argv){
    std::ifstream file(argv[1]);
    std::string line;
    std::vector<std::vector<char>> puzzle;

    while(std::getline(file, line)){
        std::vector<char> puzzle_row;
        for(const char& c : line){
            puzzle_row.push_back(c);
        }
        puzzle.push_back(puzzle_row);
    }

    size_t xmas_count{0};

    for(const std::vector<char>& row : puzzle){
        std::string row_string;
        for(char c : row){
            row_string += c;
        }
        xmas_count += count_xmas(row_string);
    }

    size_t rows = puzzle.size();
    size_t cols = puzzle[0].size();
    for(int j = 0; j < cols ; j++){
        std::string col_string;;
        for(int i = 0; i < rows; i++){
            col_string += puzzle[i][j];
        }
        xmas_count += count_xmas(col_string);
    }

    for (int col = 0; col < cols; ++col) {
        std::string diagonal_string;
        int r = 0, c = col;
        while (r < rows && c < cols) {
            diagonal_string += puzzle[r][c];
            ++r; ++c;
        }
        xmas_count += count_xmas(diagonal_string);
        diagonal_string = "";
    }
    
    for (int row = 1; row < rows; ++row) {
        std::string diagonal_string;
        int r = row, c = 0;
        while (r < rows && c < cols) {
            diagonal_string += puzzle[r][c];
            ++r; ++c;
        }
        xmas_count += count_xmas(diagonal_string);
        diagonal_string = "";
    }

    for (int col = cols - 1; col >= 0; --col) {
        std::string diagonal_string;
        int r = 0, c = col;
        while (r < rows && c >= 0) {
            diagonal_string += puzzle[r][c];
            ++r; --c;
        }
        xmas_count += count_xmas(diagonal_string);
        diagonal_string = "";
    }

    for (int row = 1; row < rows; ++row) {
        std::string diagonal_string;
        int r = row, c = cols - 1;
        while (r < rows && c >= 0) {
            diagonal_string += puzzle[r][c];
            ++r; --c;
        }
        xmas_count += count_xmas(diagonal_string);
        diagonal_string = "";
    }

    std::cout << xmas_count << "\n";

    return 0;
}