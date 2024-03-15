#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "gameManajer.h"

using namespace std;

int main() {
    string playerName;
    cout << "Game Sudoku " << "\n";
    cout << "Masukkan nama Anda: ";
    cin >> playerName;

    GameManager game(playerName); // Mulai permainan
    game.play();


    return 0;
}