#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    void drawBoard() {
        system("cls"); // clear console (Windows)
        cout << "Tic-Tac-Toe\n\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
            return false; // invalid move
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Rows & Columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer &&
                 board[i][1] == currentPlayer &&
                 board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer &&
                 board[1][i] == currentPlayer &&
                 board[2][i] == currentPlayer))
                return true;
        }

        // Diagonals
        if ((board[0][0] == currentPlayer &&
             board[1][1] == currentPlayer &&
             board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer &&
             board[1][1] == currentPlayer &&
             board[2][0] == currentPlayer))
            return true;

        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        while (true) {
            drawBoard();
            cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
            cin >> row >> col;

            if (!makeMove(row, col)) {
                cout << "Invalid move! Try again.\n";
                system("pause");
                continue;
            }

            if (checkWin()) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                drawBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
