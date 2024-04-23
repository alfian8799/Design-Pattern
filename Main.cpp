#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "gameManajer.cpp"

using namespace std;

int main() {
    string playerName;
    cout << " Game Sudoku " << "\n";
    cout << "Masukkan nama Anda: ";
    cin >> playerName;

    GameManager game(playerName);
    game.play();


    return 0;
};