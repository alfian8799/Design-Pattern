#include <iostream>
#include "player.cpp"
#include "gameManajer.h"
#include "boardGenerator.cpp"


using namespace std;

GameManager::GameManager(const string& playerName) : player(playerName) {
    BoardGenerator::Difficulty difficulty = getDifficulty();
    boardGenerator.generateSudokuPuzzle(board, difficulty); 
}

void GameManager::printBoard() const {
    cout << "Sudoku Puzzle:" << endl;
    board.printBoard();
}

bool GameManager::checkWin() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.getCell(i, j) == 0) {
                return false; 
            }
        }
    }
    return true; 
}

void GameManager::play() {
    cout << "Selamat datang, " << player.getName() << "!" << endl;
    printBoard();

    while (true) {
        int row, col, value;
        cout << "Masukkan kolom (1-9), baris (A-I), dan nilai (1-9) (mis., 1A3), atau ketik -1 untuk keluar: ";
        string input;
        cin >> input;

        if (input == "-1")
            break;

        if (input.length() != 3) {
            cout << "Format input tidak valid. Harap masukkan tiga karakter." << endl;
            continue;
        }

        col = input[0] - '1';
        row = input[1] - 'A';
        value = input[2] - '0';

        if (col < 0 || col >= 9 || row < 0 || row >= 9 || value < 1 || value > 9) {
            cout << "Input tidak valid. Harap masukkan baris (A-I), kolom (1-9), dan nilai (1-9) dalam rentang yang ditentukan." << endl;
            continue;
        }

        if (board.cellFixed(row, col)) {
            cout << "Sel ini tetap dan tidak dapat diubah." << endl;
            continue;
        }

        board.setCell(row, col, value);

        printBoard();

        if (checkWin()) {
            cout << "Selamat! Anda telah menyelesaikan permainan Sudoku." << endl;
            break;
        }
    }
}

BoardGenerator::Difficulty GameManager::getDifficulty() const {
    cout << "Pilih tingkat kesulitan:" << endl;
    cout << "1. Mudah" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Sulit" << endl;
    cout << "  " << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            return BoardGenerator::Difficulty::EASY;
        case 2:
            return BoardGenerator::Difficulty::MEDIUM;
        case 3:
            return BoardGenerator::Difficulty::HARD;
        default:
            cout << "Pilihan tidak valid, menggunakan tingkat kesulitan mudah secara default." << endl;
            return BoardGenerator::Difficulty::EASY;
    }
}
