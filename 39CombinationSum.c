#include <stdio.h>
#include <stdlib.h>

// unfinished with many logic flaws for now

void recursion(int** result, int* currentCombination, int* candidates, int candidatesSize, 
               int target, int index, int currentSize, int* returnSize, int** returnColumnSizes, 
               int currentSum) {
    if (currentSum < target){
        // if the current sum is still less than the target, keep searchin downnnn
        // lets search to the left first
        currentCombination[currentSize] = candidates[index];
        currentSum += candidates[index];

        // for (int i = 0; i < currentSize; i++) printf("%d ", currentCombination[i]);
        // printf("\n");

        recursion(result, currentCombination, candidates, candidatesSize, target, index,
                  currentSize + 1, returnSize, returnColumnSizes, currentSum);
        
        // if you can go deeper, then go deeper to the right
        if (index < candidatesSize){
            recursion(result, currentCombination, candidates, candidatesSize, target, index + 1,
                      currentSize, returnSize, returnColumnSizes, currentSum);
        }
    } else if (currentSum == target){
        // if it is the same, then basically just copy the result with the current combination
        for (int i = 0; i <= currentSize; i++) printf("%d ", currentCombination[i]);
        printf("\n");
        result[*returnSize] = malloc(currentSize * sizeof(int));

        // then, we copy it
        for (int i = 0; i < currentSize; i++){
            result[*returnSize][i] = currentCombination[i];
        };

        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    } else return; // if it is greater, than there is just no point of going anymore
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(150 * sizeof(int*));
    (*returnColumnSizes) = malloc(150 * sizeof(int));
    (*returnSize) = 0;

    // make a current function that keeps track of the array
    int* currentCombination = malloc(100 * sizeof(int));
    recursion(result, currentCombination, candidates, candidatesSize, target, 0, 0, returnSize, returnColumnSizes, 0);
    
    return result;
}

int main(){
    int numOfCanditates, target, returnSize, *returnColumnSize;
    scanf("%d %d", &numOfCanditates, &target); getchar();

    int* candidates = malloc(numOfCanditates * sizeof(int));
    for (int i = 0; i < numOfCanditates; i++){
        scanf("%d", &candidates[i]); getchar();
    };

    int** result = combinationSum(candidates, numOfCanditates, target, &returnSize, &returnColumnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++){
        printf("[");
        for (int j = 0; j < returnColumnSize[i]; j++){
            if (i == (returnColumnSize[i] - 1)) printf("[");
        };
        if (i == (returnSize - 1)) printf("]");
        else printf("] ");
    }
    printf("]\n");
    return 0;
}