#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


class Board {
private:
    vector<vector<int>> cells;
    vector<vector<bool>> fixed;

public:
    Board();

    void setCell(int row, int col, int value, bool isFixed = false);
    int getCell(int row, int col) const;
    bool isCellFixed(int row, int col) const;
    void printBoard() const;
};


Board::Board() {
    cells = vector<vector<int>>(9, vector<int>(9, 0));
    fixed = vector<vector<bool>>(9, vector<bool>(9, false));
}

void Board::setCell(int row, int col, int value, bool isFixed) {
    cells[row][col] = value;
    fixed[row][col] = isFixed;
}

int Board::getCell(int row, int col) const {
    return cells[row][col];
}

bool Board::isCellFixed(int row, int col) const {
    return fixed[row][col];
}

void Board::printBoard() const {
    std::cout << "   1 2 3   4 5 6   7 8 9" << std::endl;
    std::cout << " +-----------------------+" << std::endl;

    for (int i = 0; i < 9; ++i) {
        std::cout << char('A' + i) << "| ";
        if (i % 3 == 0 && i != 0) {
            std::cout << "---------------------" << std::endl;
            std::cout << " | ";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            if (isCellFixed(i, j)) {
                std::cout << "\033[1;31m" << cells[i][j] << "\033[0m ";
            } else {
                std::cout << cells[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << " +-----------------------+" << std::endl;
}