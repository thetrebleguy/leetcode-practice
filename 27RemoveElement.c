#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int* newArray = malloc(numsSize * sizeof(int));
    int newArrayIdx = 0;

    for (int i = 0; i < numsSize; i++){
        if (nums[i] == val) continue;
        else newArray[newArrayIdx++] = nums[i];
    };

    for (int i = 0; i < numsSize; i++){
        if (i < newArrayIdx) nums[i] = newArray[i];
        else nums[i] = 0;
    };

    free(newArray);
    return newArrayIdx;
};

int main(){
    int numOfElements, value;
    scanf("%d %d", &numOfElements, &value); getchar();

    int* numsArray = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &numsArray[i]); getchar();
    };

    int result = removeElement(numsArray, numOfElements, value);
    printf("%d\n", result);

    free(numsArray);
    return 0;
}