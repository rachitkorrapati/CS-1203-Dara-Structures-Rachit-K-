#include <stdio.h>
#include <stdbool.h>

#define N 8

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[N][N] = {0};
    
    printf("Welcome to the Eight Queens puzzle solver!\n");
    printf("Solving the Eight Queens puzzle:\n");
    
    if (solveNQueens(board, 0)) {
        printf("Solution found:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }
    
    return 0;
}
