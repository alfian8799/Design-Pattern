#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board {
private:
    vector<vector<int>> cells; // Matriks untuk menyimpan nilai setiap sel di papan Sudoku
    vector<vector<bool>> fixed; // Matriks boolean untuk menandai apakah nilai setiap sel adalah tetap atau tidak
public:
    Board() {
        cells = vector<vector<int>>(9, vector<int>(9, 0)); // Inisialisasi matriks sel dengan nilai awal 0
        fixed = vector<vector<bool>>(9, vector<bool>(9, false)); // Inisialisasi matriks tetap dengan nilai awal false
    }

    void setCell(int row, int col, int value, bool isFixed = false) {
        cells[row][col] = value; // Tetapkan nilai ke sel tertentu di papan Sudoku
        fixed[row][col] = isFixed; // Tetapkan status sel tetap atau tidak
    }

    int getCell(int row, int col) const {
        return cells[row][col]; // Ambil nilai sel tertentu dari papan Sudoku
    }

    bool isCellFixed(int row, int col) const {
        return fixed[row][col]; // Periksa apakah sel tertentu tetap atau tidak
    }

    void printBoard() const {
        // Cetak label sumbu X (angka)
        cout << "   1 2 3   4 5 6   7 8 9" << endl;
        cout << " +-----------------------+" << endl;

        for (int i = 0; i < 9; ++i) {
            // Cetak label sumbu Y (huruf abjad)
            cout << char('A' + i) << "| ";
            if (i % 3 == 0 && i != 0) {
                cout << "---------------------" << endl;
                cout << " | ";
            }
            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0) {
                    cout << "| ";
                }
                if (isCellFixed(i, j)) {
                    cout << "\033[1;31m" << cells[i][j] << "\033[0m "; // Cetak nomor tetap dalam warna merah
                } else {
                    cout << cells[i][j] << " "; // Cetak nilai sel pada papan Sudoku
                }
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
    Player(const string& playerName) : name(playerName) {} // Inisialisasi nama pemain

    string getName() const {
        return name; // Ambil nama pemain
    }
};

class GameManager {
private:
    Board board; // Objek papan Sudoku
    Player player; // Objek pemain
public:
    GameManager(const string& playerName) : player(playerName) {
        srand(time(NULL)); // Inisialisasi seed generator angka acak
        generateSudokuPuzzle(); // Generate teka-teki Sudoku
    }

    bool isNumberUsedInRow(int row, int num) const {
        for (int col = 0; col < 9; ++col) {
            if (board.getCell(row, col) == num) {
                return true; // Periksa apakah nomor digunakan di baris tertentu
            }
        }
        return false;
    }

    bool isNumberUsedInCol(int col, int num) const {
        for (int row = 0; row < 9; ++row) {
            if (board.getCell(row, col) == num) {
                return true; // Periksa apakah nomor digunakan di kolom tertentu
            }
        }
        return false;
    }

 // Fungsi untuk menghasilkan puzzle Sudoku
void generateSudokuPuzzle() {
    // Inisialisasi array untuk memantau angka mana yang sudah digunakan dalam setiap baris, kolom, dan grid
    bool usedInRow[9][10] = {false};
    bool usedInCol[9][10] = {false};
    bool usedInGrid[3][3][10] = {false};

    int numToPlace = 1; // Angka yang akan ditempatkan dalam kotak berikutnya

    for (int i = 0; i < 79; ++i) { // Loop untuk menempatkan angka dari 1 hingga 9 dalam setiap baris, kolom, dan grid
        int row = i / 9; // Hitung baris berdasarkan nomor kotak
        int col = i % 9; // Hitung kolom berdasarkan nomor kotak
        int gridRow = row / 3; // Hitung baris grid (0, 1, atau 2)
        int gridCol = col / 3; // Hitung kolom grid (0, 1, atau 2)
        
        // Periksa apakah angka yang akan ditempatkan sudah digunakan dalam baris, kolom, atau grid
        while (usedInRow[row][numToPlace] || usedInCol[col][numToPlace] || usedInGrid[gridRow][gridCol][numToPlace]) {
            ++numToPlace; // Jika sudah digunakan, coba dengan angka berikutnya
            if (numToPlace > 9) // Jika semua angka sudah digunakan, kembali ke angka pertama
                numToPlace = 1;
        }
        
        // Tandai angka yang sudah digunakan
        usedInRow[row][numToPlace] = true;
        usedInCol[col][numToPlace] = true;
        usedInGrid[gridRow][gridCol][numToPlace] = true;

        // Tetapkan sel dengan angka yang dihasilkan sebagai angka yang tetap (tidak dapat diubah)
        board.setCell(row, col, numToPlace, true);

        // Geser angka yang akan ditempatkan ke angka berikutnya
        ++numToPlace;
        if (numToPlace > 9) // Jika semua angka sudah digunakan, kembali ke angka pertama
            numToPlace = 1;
    }
}





    void printBoard() const {
        cout << "Sudoku Puzzle:" << endl;
        board.printBoard(); // Cetak papan Sudoku
    }

    void play() {
        cout << "Selamat datang, " << player.getName() << "!" << endl;
        printBoard(); // Cetak papan Sudoku

        // Loop permainan
        while (true) {
            int row, col, value;
            cout << "Masukkan kolom (1-9), baris (A-I), dan nilai (1-9) (mis., 1A3): ";
            string input;
            cin >> input;

            if (input == "-1")
                break;

            // Memeriksa apakah input memiliki format yang benar
            if (input.length() != 3) {
                cout << "Format input tidak valid. Harap masukkan tiga karakter." << endl;
                continue;
            }

            // Mendapatkan kolom, baris, dan nilai dari input
            col = input[0] - '1';
            row = input[1] - 'A';
            value = input[2] - '0';

            // Validasi input
            if (col < 0 || col >= 9 || row < 0 || row >= 9 || value < 1 || value > 9) {
                cout << "Input tidak valid. Harap masukkan baris (A-I), kolom (1-9), dan nilai (1-9) dalam rentang yang ditentukan." << endl;
                continue;
            }

            // Periksa apakah sel tetap, jika ya, jangan izinkan pemain mengubahnya
            if (board.isCellFixed(row, col)) {
                cout << "Sel ini tetap dan tidak dapat diubah." << endl;
                continue;
            }

            // Tetapkan nilai sel pada papan dengan nilai yang dimasukkan
            board.setCell(row, col, value);
            printBoard(); // Cetak papan Sudoku
        }
    }
};

int main() {
    string playerName;
    cout << "Game Sudoku " << "\n";
    cout << "Masukkan nama Anda: ";
    cin >> playerName;

    GameManager game(playerName); // Mulai permainan
    game.play();

    return 0;
}