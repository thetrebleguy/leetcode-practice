#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int lowRow = 0;
    int highRow = matrixSize - 1;
    int midRow = 0;

    while (lowRow <= highRow){
        midRow = lowRow + (highRow - lowRow) / 2;
        printf("%d\n", matrix[midRow][0]);
        if (matrix[midRow][0] == target){
            return true;
        } else if (matrix[midRow][0] < target){
            lowRow = midRow + 1;
        } else {
            highRow = midRow - 1;
        }
    };

    midRow = highRow;
    if (midRow < 0) return false;

    // if nothing matches on the first index, we use the latest 
    int lowColumn = 0;
    int highColumn = matrixColSize[midRow] - 1;
    int midColumn = 0;

    while (lowColumn <= highColumn){
        midColumn = lowColumn + (highColumn - lowColumn) / 2;
        if (matrix[midRow][midColumn] == target){
            return true;
        } else if (matrix[midRow][midColumn] < target){
            lowColumn = midColumn + 1;
        } else {
            highColumn = midColumn - 1;
        }
    };

    return false;
}

int main(){
    int rows, columns, target;
    scanf("%d %d", &rows, &columns); getchar();

    int** matrix = (int**)malloc(sizeof(int *) * rows);
    int* matrixColSize = malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; i++){
        matrix[i] = (int*)malloc(sizeof(int) * columns);
        matrixColSize[i] = columns;
    };

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            scanf("%d", &matrix[i][j]); getchar();
        }
    };

    scanf("%d", &target); getchar();

    bool result = searchMatrix(matrix, rows, matrixColSize, target);
    printf("%s\n", result ? "true" : "false");
    return 0;
}
