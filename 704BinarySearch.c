#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    };

    return -1;
}

int main(){
    int numOfElements, target;
    scanf("%d", &numOfElements); getchar();

    int* nums = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &nums[i]); getchar();
    };

    scanf("%d", &target);

    int index = search(nums, numOfElements, target);
    printf("%d\n", index);
    return 0;
}