#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    char rows[9][9];
    char cols[9][9];
    char square[9][9];

    // fill the board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            rows[i][j] = '.';
            cols[i][j] = '.';
            square[i][j] = '.';
        }
    }

    // this is for all the rules checking
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == '.') continue;
            
            int num = board[i][j] - '1';  // 0-8
            int box = (i/3)*3 + (j/3);    // the 3x3 box
            
            if (rows[i][num] != '.' || cols[j][num] != '.' || square[box][num] != '.') {
                return false;
            }
            
            rows[i][num] = board[i][j];
            cols[j][num] = board[i][j];
            square[box][num] = board[i][j];
        };
    };

    return true;
}

int main(){
    char **board = malloc(9 * sizeof(char *));
    for (int i = 0; i < 9; i++){
        board[i] = malloc(10 * sizeof(char));
    }

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf("%c", &board[i][j]); getchar();
        };
    };

    bool result = isValidSudoku(board, 9, NULL);
    printf("%s\n", result ? "true" : "false");
    
    for (int i = 0; i < 9; i++){
        free(board[i]);
    };

    free(board);
    return 0;
}