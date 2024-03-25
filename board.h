#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
#pragma once
using namespace std;

class Board {
private:
    vector<vector<int>> cells;
    vector<vector<bool>> fixed;

public:
    Board();

    void setCell(int row, int col, int value, bool isFixed = false);
    int getCell(int row, int col) const;
    bool cellFixed(int row, int col) const;
    void printBoard() const;
};