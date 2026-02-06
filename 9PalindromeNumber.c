#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool isPalindrome(int x) {
    // calculate the amount of digits
    int temp = x;
    int numOfDigits = 0;

    do {
        temp /= 10;
        numOfDigits++;
    } while (temp > 0);

    // if negative, then immediately return false
    int* nums = malloc(numOfDigits * sizeof(int));
    if (x < 0) return false;
    else if (numOfDigits == 1) return true;
    else {
        // store each digit in the array
        for (int i = 0; i < numOfDigits; i++){
            nums[i] = x / pow(10, numOfDigits - i - 1);
            x %= (int)pow(10, numOfDigits - i - 1);
        };

        // lets print it first
        for (int i = 0; i < numOfDigits / 2; i++){
            if (nums[i] != nums[numOfDigits - i - 1]){
                free(nums);
                return false;
            }
        };
    };  

    free(nums);
    return true;
};

int main(){
    int num;
    scanf("%d", &num);
    printf("%s\n", isPalindrome(num) ? "true" : "false");
    return 0;
};