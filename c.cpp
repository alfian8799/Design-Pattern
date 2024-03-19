#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Sudoku {
private:
    std::vector<std::vector<int>> board;
    const int size = 9;

    bool isValid(int row, int col, int num) {
        // Check row and column
        for (int i = 0; i < size; ++i) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }

        // Check 3x3 grid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve() {
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (board[row][col] == 0) {
                    for (int num = 1; num <= size; ++num) {
                        if (isValid(row, col, num)) {
                            board[row][col] = num;
                            if (solve()) {
                                return true;
                            }
                            board[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    Sudoku() : board(size, std::vector<int>(size, 0)) {}

    void generate() {
        srand(time(nullptr));

        // Step 1: Fill diagonal 3x3 grids with random numbers
        for (int i = 0; i < size; i += 3) {
            std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            std::random_shuffle(nums.begin(), nums.end());
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    board[i + j][i + k] = nums[j * 3 + k];
                }
            }
        }

        // Step 2: Solve the Sudoku board
        solve();

        // Step 3: Remove random numbers to make it easy
        int emptyCells = size * size / 3; // Adjust for difficulty
        while (emptyCells > 0) {
            int row = rand() % size;
            int col = rand() % size;
            if (board[row][col] != 0) {
                board[row][col] = 0;
                --emptyCells;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << board[i][j] << " ";
                if ((j + 1) % 3 == 0 && j != size - 1) {
                    std::cout << "| ";
                }
            }
            std::cout << std::endl;
            if ((i + 1) % 3 == 0 && i != size - 1) {
                std::cout << "------+-------+------" << std::endl;
            }
        }
    }
};

int main() {
    Sudoku sudoku;
    sudoku.generate();
    sudoku.print();
    return 0;
}
