#include <iostream>
#include <limits>

using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

   
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' },
                        { ' ', ' ', ' ' },
                        { ' ', ' ', ' ' } };
    char player = 'X';
    int row, col;
    int turn;

    cout << "Welcome\n";

    for (turn = 0; turn < 9; turn++) {
        drawBoard(board);

        while (true) {
            cout << "Player " << player << ", enter row (1-3) and column (1-3): ";
            if (!(cin >> row >> col)) {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // Add this line to wait for new input
            } else if (row < 1 || row > 3 || col < 1 || col > 3) {
                cout << "Invalid move. Row and column must be between 1 and 3.\n";
            } else if (board[row - 1][col - 1] != ' ') { // Decrement row and col by 1
                cout << "Invalid move. Cell is already occupied.\n";
            } else {
                break;
            }
        }

        board[row - 1][col - 1] = player; // Decrement row and col by 1

        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}