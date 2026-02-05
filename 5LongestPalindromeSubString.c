#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int length = strlen(s);
    int longestLength = 1;
    int maxCenterIndx;
    static char longestString[1001] = "";

    for (int centerIndx = 0; centerIndx < length; centerIndx++){
        if (length % 2 == 1){
            // odd
            int i = centerIndx, j = centerIndx;
            while (i >= 0 && j < length && (s[i] == s[j])){
                if ((j - i + 1) > longestLength){
                    longestLength = (j - i + 1);
                    maxCenterIndx = centerIndx;
                };
                i--;
                j++;
            };
        } else {
            // even
            int i = centerIndx, j = centerIndx + 1;
            while (i >= 0 && j < length && (s[i] == s[j])){
                if ((j - i + 1) > longestLength){
                    longestLength = (j - i + 1);
                    maxCenterIndx = centerIndx;
                };
                i--;
                j++;
            };
        };
    };

    int index = 0;
    // if odd
    if (length % 2 == 1){
        for (int i = maxCenterIndx - longestLength / 2; i <= maxCenterIndx + longestLength /2; i++){
            longestString[index] = s[i];
            index++;

            if (i == maxCenterIndx + longestLength / 2){
                longestString[index + 1] = '\0';
            }
        };
    } else { // if even
        for (int i = maxCenterIndx - longestLength / 2 + 1; i <= maxCenterIndx + (longestLength / 2); i++){
            longestString[index] = s[i];
            index++;

            if (i == maxCenterIndx + longestLength / 2){
                longestString[index + 1] = '\0';
            }
        };
    };

    return longestString;
};

int main(){
    printf("%s\n", longestPalindrome("cbbd"));
    return 0;
}