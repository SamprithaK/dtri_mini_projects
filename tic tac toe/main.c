#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char currentPlayer = 'X';
    int moves = 0;
    int row, col, pos;

    while (moves < SIZE * SIZE) {
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &pos);

        if (pos < 1 || pos > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        row = (pos - 1) / SIZE;
        col = (pos - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Spot already taken! Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        if (checkWinner(board, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            return 0;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printf("It's a draw!\n");
    return 0;
}
