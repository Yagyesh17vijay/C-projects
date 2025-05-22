#include <stdio.h>
#include <stdlib.h>

char board[3][3]; 
char player1Symbol, player2Symbol;

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

int checkFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    char playAgain;
    printf("Player 1, choose your symbol: ");
    scanf(" %c", &player1Symbol);
    
    do {
        printf("Player 2, choose your symbol (different from Player 1): ");
        scanf(" %c", &player2Symbol);
        if (player2Symbol == player1Symbol) {
            printf("Both players cannot have the same symbol. Try again.\n");
        }
    } while (player2Symbol == player1Symbol);

    do {
        initBoard();
        int player = 1;
        int row, col;

        while (1) {
            printBoard();
            printf("Player %d (%c), enter your move (row col): ", player, (player == 1) ? player1Symbol : player2Symbol);
            scanf("%d %d", &row, &col);
            row--;
            col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = (player == 1) ? player1Symbol : player2Symbol;

                if (checkWin(board[row][col])) {
                    printBoard();
                    printf("Player %d (%c) wins!\n", player, board[row][col]);
                    break;
                }

                if (checkFull()) {
                    printBoard();
                    printf("It's a draw!\n");
                    break;
                }

                player = (player == 1) ? 2 : 1;
            } else {
                printf("Invalid move. Try again.\n");
            }
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}