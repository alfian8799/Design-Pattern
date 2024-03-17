#include "board.h" 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#pragma once

class BoardGenerator {
public:
    static void generateSudokuPuzzle(Board& board);
};


const int numInitialCells = 78;

void BoardGenerator::generateSudokuPuzzle(Board& board) {
    bool usedInRow[9][10] = {false};
    bool usedInCol[9][10] = {false};
    bool usedInGrid[3][3][10] = {false};

    int numToPlace = 1;

    for (int i = 0; i < numInitialCells; ++i) {
        int row = i / 9;
        int col = i % 9;
        int gridRow = row / 3;
        int gridCol = col / 3;

        while (usedInRow[row][numToPlace] || usedInCol[col][numToPlace] || usedInGrid[gridRow][gridCol][numToPlace]) {
            ++numToPlace;
            if (numToPlace > 9)
                numToPlace = 1;
        }

        usedInRow[row][numToPlace] = true;
        usedInCol[col][numToPlace] = true;
        usedInGrid[gridRow][gridCol][numToPlace] = true;

        board.setCell(row, col, numToPlace, true);

        ++numToPlace;
        if (numToPlace > 9)
            numToPlace = 1;
    }
}
