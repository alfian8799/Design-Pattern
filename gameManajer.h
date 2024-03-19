#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
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
    bool checkWinCondition() const;
};

GameManager::GameManager(const string& playerName) : player(playerName) {
    boardGenerator.generateSudokuPuzzle(board); 
}

void GameManager::printBoard() const {
    cout << "Sudoku Puzzle:" << endl;
    board.printBoard();
}

bool GameManager::checkWinCondition() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.getCell(i, j) == 0) {
                return false; // Ada sel kosong, permainan belum selesai
            }
        }
    }
    return true; // Semua sel terisi, permainan selesai
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

        if (checkWinCondition()) {
            cout << "Selamat! Anda telah menyelesaikan permainan Sudoku." << endl;
            break;
        }
    }
}
