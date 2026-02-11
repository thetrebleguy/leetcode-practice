#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // multiply all the elements
    int multiplyAllElements = 1;
    int amountOfZero = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 0){
            amountOfZero++;
            continue;
        } else {
            multiplyAllElements *= nums[i];
        }
    };

    // if zero does not exists
    if (!amountOfZero){
        for (int i = 0; i < numsSize; i++){
            nums[i] = multiplyAllElements / nums[i];
        };
    } else {
        if (amountOfZero == 1) {
            // if there is just 1 0's, then set everything to 0 except nums[i] = 0
            for (int i = 0; i < numsSize; i++){
                if (nums[i] != 0) nums[i] = 0;
                else nums[i] = multiplyAllElements;
            };
        } else {
            // if there are more than 1 0's, then set everything as 0
            for (int i = 0; i < numsSize; i++){
                nums[i] = 0;
            };
        }
    }

    (*returnSize) = numsSize;
    return nums;
}

int main(){
    int numOfElements, returnSize;
    scanf("%d", &numOfElements); getchar();

    int* nums = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &nums[i]); getchar();
    };

    nums = productExceptSelf(nums, numOfElements, &returnSize);
    for (int i = 0; i < numOfElements; i++){
        printf("%d ", nums[i]);
    };

    return 0;
}