#include <iostream>
#include <vector>

#include "sudoku.cc"

int main() {
    std::vector <std::vector<short>> m = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0}, 
        {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
        {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
        {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
        {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
        {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
        {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
        {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    Sudoku sudoku(m);
    if (sudoku.solve())
        std::cout << sudoku << std::endl;
    else
        std::cout << "No solution exists" << std::endl; 

    return 0;

}