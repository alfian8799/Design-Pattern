#pragma once
#include <iostream>
#include "board.cpp"
#include "boardGenerator.h"



void BoardGenerator::generateSudokuPuzzle(Board& board, Difficulty difficulty) {
    switch (difficulty) {
        case EASY:
            easyPuzzle(board);
            break;
        case MEDIUM:
            mediumPuzzle(board);
            break;
        case HARD:
            hardPuzzle(board);
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

void BoardGenerator::mediumPuzzle(Board& board) {
    std::ifstream file("mediumsudoku.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Gagal membuka file medium_sudoku.txt" << std::endl;
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


    file.close();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudokuNumbers[i][j] != 0) {
                board.setCell(i, j, sudokuNumbers[i][j], true);
            }
        }
    }
}

void BoardGenerator::hardPuzzle(Board& board) {
    std::ifstream file("hardsudoku.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Gagal membuka file hard_sudoku.txt" << std::endl;
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


    file.close();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudokuNumbers[i][j] != 0) {
                board.setCell(i, j, sudokuNumbers[i][j], true);
            }
        }
    }
}


