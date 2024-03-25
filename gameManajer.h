#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "board.h"
#include "player.cpp"
#include "boardGenerator.cpp" 

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
    bool checkWin() const;
    BoardGenerator::Difficulty getDifficulty() const;
};
