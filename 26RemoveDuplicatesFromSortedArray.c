#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int* newNums = malloc(numsSize * sizeof(int));
    int newNumsIndex = 0;
    
    // fill the entire thing with -101
    for (int i = 0; i < numsSize; i++){
        newNums[i] = -101;
    };

    // the first element goes in
    newNums[newNumsIndex++] = nums[0];

    // check through the array
    for (int i = 1; i < numsSize; i++){
        if (nums[i] != newNums[newNumsIndex-1]){
            newNums[newNumsIndex] = nums[i];
            newNumsIndex++;
        };
    }; 

    // copy the rest
    for (int i = 0; i < numsSize; i++){
        if (i < newNumsIndex){
            nums[i] = newNums[i];
        } else {
            nums[i] = 0;
        }
    };

    free(newNums);
    return newNumsIndex;
}

int main(){
    int amountOfNumbers;
    scanf("%d", &amountOfNumbers); getchar();

    int* nums = malloc(amountOfNumbers * sizeof(int));
    for (int i = 0; i < amountOfNumbers; i++){
        scanf("%d", &nums[i]); getchar();
    };

    int result = removeDuplicates(nums, amountOfNumbers);
    for (int i = 0; i < amountOfNumbers; i++){
        printf("%d ", nums[i]);  
    };

    free(nums);
    return 0;
}