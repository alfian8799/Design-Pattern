#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "board.h"
#include "player.h"
using namespace std;

class GameManager {
private:
    Board board;
    Player player;

public:
    GameManager(const string& playerName);
    bool isNumberUsedInRow(int row, int num) const;
    bool isNumberUsedInCol(int col, int num) const;
    void generateSudokuPuzzle();
    void printBoard() const;
    void play();
};


GameManager::GameManager(const string& playerName) : player(playerName) {
    srand(time(NULL));
    generateSudokuPuzzle();
}

bool GameManager::isNumberUsedInRow(int row, int num) const {
    for (int col = 0; col < 9; ++col) {
        if (board.getCell(row, col) == num) {
            return true;
        }
    }
    return false;
}

bool GameManager::isNumberUsedInCol(int col, int num) const {
    for (int row = 0; row < 9; ++row) {
        if (board.getCell(row, col) == num) {
            return true;
        }
    }
    return false;
}

void GameManager::generateSudokuPuzzle() {
    
    bool usedInRow[9][10] = {false};
    bool usedInCol[9][10] = {false};
    bool usedInGrid[3][3][10] = {false};

    int numToPlace = 1; 

    for (int i = 0; i < 79; ++i) {
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