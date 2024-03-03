
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board {
private:
    vector<vector<int>> cells;
public:
    Board() {
        
        cells = vector<vector<int>>(9, vector<int>(9, 0));
    }

    void setCell(int row, int col, int value) {
        cells[row][col] = value;
    }

    int getCell(int row, int col) const {
        return cells[row][col];
    }

   void printBoard() const {
        // Print label sumbu X (angka)
        cout << "   1 2 3   4 5 6   7 8 9" << endl;
        cout << " +-----------------------+" << endl;

        for (int i = 0; i < 9; ++i) {
            // Print label sumbu Y (huruf abjad)
            cout << char('A' + i) << "| ";
            if (i % 3 == 0 && i != 0) {
                cout << "---------------------" << endl;
                cout << " | ";
            }
            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0) {
                    cout << "| ";
                }
                cout << cells[i][j] << " ";
            }
            cout << endl;
        }
        cout << " +-----------------------+" << endl;
    }
};

class Player {
private:
    string name;
public:
    Player(const string& playerName) : name(playerName) {}

    string getName() const {
        return name;
    }
};

class GameManager {
private:
    Board board;
    Player player;
public:
    GameManager(const string& playerName) : player(playerName) {
        srand(time(NULL));
        generateSudokuPuzzle();
    }

    void generateSudokuPuzzle() {

        for (int i = 0; i < 30; ++i) {
            int row = rand() % 9;
            int col = rand() % 9;
            int num = rand() % 9 + 1; // Random number 1 and 9
            board.setCell(row, col, num);
        }
    }

    void printBoard() const {
        cout << "Sudoku Puzzle:" << endl;
        board.printBoard();
    }

     void play() {
    cout << "Welcome, " << player.getName() << "!" << endl;
    printBoard();

    // Game loop
    while (true) {
        int row, col, value;
        cout << "Enter column (1-9), row (A-I), and value (1-9) (e.g., 1A3): ";
        string input;
        cin >> input;

        if (input == "-1")
            break;

        // Memeriksa apakah input memiliki format yang benar
        if (input.length() != 3) {
            cout << "Invalid input format. Please enter three characters." << endl;
            continue;
        }

        // Mendapatkan kolom, baris, dan nilai dari input
        col = input[0] - '1';
        row = input[1] - 'A';
        value = input[2] - '0';

        // Validasi input
        if (col < 0 || col >= 9 || row < 0 || row >= 9 || value < 1 || value > 9) {
            cout << "Invalid input. Please enter row (A-I), column (1-9), and value (1-9) within the specified range." << endl;
            continue;
        }

        // Set sel pada papan dengan nilai yang dimasukkan
        board.setCell(row, col, value);
        printBoard();
    }
}

};

int main() {
    
    
    string playerName;
    cout << "Gamee Sudoku " << "\n";
    cout << "Enter your name: ";

    cin >> playerName;

    GameManager game(playerName);
    game.play();

    return 0;
}

