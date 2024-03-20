

// #include "board.h" 
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <string>
// #pragma once

// class BoardGenerator {
// public:
//     static void generateSudokuPuzzle(Board& board);
// };

// void BoardGenerator::generateSudokuPuzzle(Board& board) {
    
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


// // const int numInitialCells = 78;

// // void BoardGenerator::generateSudokuPuzzle(Board& board) {
// //     bool usedInRow[9][10] = {false};
// //     bool usedInCol[9][10] = {false};
// //     bool usedInGrid[3][3][10] = {false};

// //     int numToPlace = 1;

// //     for (int i = 0; i < numInitialCells; ++i) {
// //         int row = i / 9;
// //         int col = i % 9;
// //         int gridRow = row / 3;
// //         int gridCol = col / 3;

// //         while (usedInRow[row][numToPlace] || usedInCol[col][numToPlace] || usedInGrid[gridRow][gridCol][numToPlace]) {
// //             ++numToPlace;
// //             if (numToPlace > 9)
// //                 numToPlace = 1;
// //         }

// //         usedInRow[row][numToPlace] = true;
// //         usedInCol[col][numToPlace] = true;
// //         usedInGrid[gridRow][gridCol][numToPlace] = true;

// //         board.setCell(row, col, numToPlace, true);

// //         ++numToPlace;
// //         if (numToPlace > 9)
// //             numToPlace = 1;
// //     }
// // }


// #include "board.h"
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <string>
// #pragma once

// class BoardGenerator {
// public:
//     enum Difficulty { EASY, MEDIUM, HARD };

//     static void generateSudokuPuzzle(Board& board, Difficulty difficulty);
// private:
//     static void fillEasyPuzzle(Board& board);
// };

// void BoardGenerator::generateSudokuPuzzle(Board& board, Difficulty difficulty) {
//     switch (difficulty) {
//         case EASY:
//             fillEasyPuzzle(board);
//             break;
//         case MEDIUM:
//             // implementasi untuk tingkat kesulitan sedang
//             break;
//         case HARD:
//             // implementasi untuk tingkat kesulitan sulit
//             break;
//         default:
//             fillEasyPuzzle(board); // Jika kesulitan tidak valid, gunakan tingkat kesulitan mudah secara default
//             break;
//     }
// }

// void BoardGenerator::fillEasyPuzzle(Board& board) {
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
