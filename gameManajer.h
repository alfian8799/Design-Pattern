#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#pragma once
#include "board.h"
#include "player.h"
#include "boardGenerator.h" 
using namespace std;



class GameManager {
private:
    Board board;
    Player player;
    BoardGenerator boardGenerator; 
public:
    GameManager(const string& playerName);
    void printBoard() const;
    void play();
};


GameManager::GameManager(const string& playerName) : player(playerName) {
    boardGenerator.generateSudokuPuzzle(board); 
}

void GameManager::printBoard() const {
    cout << "Sudoku Puzzle:" << endl;
    board.printBoard();
}


void GameManager::play() {
    cout << "Selamat datang, " << player.getName() << "!" << endl;
    printBoard();

    while (true) {
        int row, col, value;
        cout << "Masukkan kolom (1-9), baris (A-I), dan nilai (1-9) (mis., 1A3): ";
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
            cout << "Input tidak valid. Harap masukkan baris (A-I), kolom (1-9), dan nilai (1-9) dalam rentang yang ditentukan." << std::endl;
            continue;
        }

        if (board.isCellFixed(row, col)) {
            cout << "Sel ini tetap dan tidak dapat diubah." << endl;
            continue;
        }

        board.setCell(row, col, value);
        printBoard();
    }
}