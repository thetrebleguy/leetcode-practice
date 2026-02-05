#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main(){
    int numOfElements;
    scanf("%d", &numOfElements); getchar();

    int* numsArray = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &numsArray[i]); getchar();  
    };

    int value = singleNumber(numsArray, numOfElements);
    printf("%d\n", value);
    free(numsArray);
    return 0;
}