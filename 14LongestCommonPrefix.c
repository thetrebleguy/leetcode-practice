#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize){
    if (strsSize == 0) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }
    
    // first we find the minimum length of the string in the strs
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) minLen = len;
    };

    // after that, you allocate it with the max length possible
    char* result = malloc(minLen + 1);
    int prefixLength = 0;

    // then you just compare the thingies
    for (int i = 0; i < minLen; i++) {
        char currentChar = strs[0][i];
        int allMatch = 1;
        
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != currentChar) { // if it doesnt match once, then break
                allMatch = 0;
                break;
            }
        }
        
        if (allMatch) {
            result[prefixLength++] = currentChar;
        } else {
            break;
        }
    }

    result[prefixLength] = '\0';
    return result;
}

int main(){
    int amountOfString;
    scanf("%d", &amountOfString); getchar();

    char** strs = malloc(amountOfString * sizeof(char*));
    for (int i = 0; i < amountOfString; i++){
        strs[i] = malloc(201);
        scanf("%s", strs[i]);
        getchar();
    };

    char* result = longestCommonPrefix(strs, amountOfString);
    printf("Longest common prefix: %s\n", result);
    
    free(result);
    for (int i = 0; i < amountOfString; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}