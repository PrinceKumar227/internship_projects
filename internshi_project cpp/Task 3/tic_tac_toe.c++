#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "\nTic Tac Toe Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Row check
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Column check
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Diagonal check
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  // If any cell is empty, no draw yet
            }
        }
    }
    return true;  // No empty cells, it's a draw
}

int main() {
    char playAgain;
    do {
        char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
        char player = 'X';
        int row, col;
        bool gameWon = false;

        while (!gameWon) {
            printBoard(board);
            cout << "Player " << player << "'s turn.\n";
            cout << "Enter row and column (0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move, try again.\n";
                continue;
            }

            board[row][col] = player;

            if (checkWin(board, player)) {
                printBoard(board);
                cout << "Player " << player << " wins!\n";
                gameWon = true;
            } else if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!\n";
                gameWon = true;
            }

            player = (player == 'X') ? 'O' : 'X';  // Switch player
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
