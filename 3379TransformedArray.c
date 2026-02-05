#include <stdio.h>
#include <stdlib.h>

int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int *result = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        if (nums[i] > 0){
            int index = (i + nums[i]) % numsSize;
            result[i] = nums[index];
        } else if (nums[i] < 0){
            int index = (i + nums[i]) % numsSize;
            if (index < 0) index += numsSize;
            result[i] = nums[index];
        } else {
            result[i] = nums[i];
        };
    };

    *returnSize = numsSize;
    return result;
}

int main(){
    int numOfElements, returnSize;
    scanf("%d", &numOfElements); getchar();

    int* nums = malloc(numOfElements * sizeof(int));

    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &nums[i]); getchar();
    };

    int* result = constructTransformedArray(nums, numOfElements, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    };
    
    free(nums);
    free(result);
    return 0;
}