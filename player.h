#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player {
private:
    string name;

public:
    Player(const string& playerName);
    string getName() const;
};
