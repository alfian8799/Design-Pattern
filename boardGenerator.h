#include <fstream>
#include <sstream>
#include "board.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#pragma once

class BoardGenerator {
public:
    enum Difficulty { EASY };

    static void generateSudokuPuzzle(Board& board, Difficulty difficulty);
private:
    static void easyPuzzle(Board& board);
};

void BoardGenerator::generateSudokuPuzzle(Board& board, Difficulty difficulty) {
    switch (difficulty) {
        case EASY:
            easyPuzzle(board);
            break;
    }
}

void BoardGenerator::easyPuzzle(Board& board) {
    std::ifstream file("easysudoku.txt"); // Buka file teks
    if (!file.is_open()) {
        std::cerr << "Error: Gagal membuka file easy_sudoku.txt" << std::endl;
        return;
    }

    int sudokuNumbers[9][9];
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < 9) { // Baca baris per baris dari file teks
        std::stringstream ss(line);
        int col = 0;
        int number;
        while (ss >> number && col < 9) { // Baca angka dari setiap baris
            sudokuNumbers[row][col] = number;
            ++col;
        }
        ++row;
    }

    file.close(); // Tutup file

    // Setel sel pada papan berdasarkan data dari file teks
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudokuNumbers[i][j] != 0) {
                board.setCell(i, j, sudokuNumbers[i][j], true);
            }
        }
    }
}































































// #include "board.h"
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <string>
// #pragma once

// class BoardGenerator {
// public:
//     enum Difficulty { EASY };

//     static void generateSudokuPuzzle(Board& board, Difficulty difficulty);
// private:
//     static void easyPuzzle(Board& board);
// };

// void BoardGenerator::generateSudokuPuzzle(Board& board, Difficulty difficulty) {
//     switch (difficulty) {
//         case EASY:
//             easyPuzzle(board);
//             break;
//     }
// }

// void BoardGenerator::easyPuzzle(Board& board) {
//     int sudokuNumbers[9][9] = {
//         {4, 0, 2, 0, 0, 0, 0, 0, 9},
//         {0, 9, 6, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 1, 0},
//         {0, 0, 7, 4, 7, 0, 0, 8, 3},
//         {0, 6, 0, 0, 0, 0, 0, 0, 4},
//         {8, 0, 0, 0, 1, 2, 0, 9, 0},
//         {6, 1, 8, 9, 4, 0, 2, 0, 5},
//         {7, 0, 4, 3, 5, 1, 9, 0, 8},
//         {0, 3, 0, 0, 0, 0, 7, 0, 1}
//     };

//     for (int i = 0; i < 9; ++i) {
//         for (int j = 0; j < 9; ++j) {
//             if (sudokuNumbers[i][j] != 0) {
//                 board.setCell(i, j, sudokuNumbers[i][j], true);
//             }
//         }
//     }
// }
