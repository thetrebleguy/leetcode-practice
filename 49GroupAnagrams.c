#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// UNFINISHED

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int numOfUniqueAnagrams = 0;
    int** hashTable = (int**)malloc(strsSize * sizeof(int*));
    int groupSizeTable[strsSize]; // this basically tells how large the size of each corresponding group

    for (int i = 0; i < strsSize; i++){
        hashTable[i] = (int*)malloc(26 * sizeof(int));
        
        // make everything 0
        for (int j = 0; j < 26; j++){
            hashTable[i][j] = 0;
        };
    };

    // lets check every string first
    for (int i = 0; i < strsSize; i++){
        int length = strlen(strs[i]);
        int currentHashTable[26] = {0};

        // put every char into the current hash table
        for (int j = 0; j < length; j++){
            currentHashTable[strs[i][j] - 'a']++;
        };

        int anagramExisted = 0;
        for (int anagramIndex = 0; anagramIndex < numOfUniqueAnagrams; anagramIndex++){
            for (int k = 0; k < 26; k++){
                if (currentHashTable[k] == hashTable[anagramIndex][k] && (k == 25) && !anagramExisted){
                    anagramExisted = 1;
                    groupSizeTable[anagramIndex]++;
                    break;
                } else if (currentHashTable[k] != hashTable[anagramIndex][k]){
                    break;
                }
            };
                
            if (anagramExisted == 1) break;
        };

        // if there is no anagram, then lets make another group
        if (!anagramExisted){
            for (int j = 0; j < length; j++){
                hashTable[numOfUniqueAnagrams][strs[i][j] - 'a']++;
            };
            groupSizeTable[numOfUniqueAnagrams] = 1;
            numOfUniqueAnagrams++;
        }
    };

    char*** result = malloc(numOfUniqueAnagrams * sizeof(char**));
    for (int i = 0; i < numOfUniqueAnagrams; i++){
        result[i] = malloc(groupSizeTable[i] * sizeof(char*));
    };

    // reset the groupsizetable
    *returnColumnSizes = malloc(numOfUniqueAnagrams * sizeof(int));
    for (int i = 0; i < numOfUniqueAnagrams; i++){
        (*returnColumnSizes)[i] = groupSizeTable[i];
        groupSizeTable[i] = 0;
    };

    // now add them into the group
    for (int i = 0; i < strsSize; i++){
        int length = strlen(strs[i]);
        int currentHashTable[26] = {0};

        // put every char into the current hash table
        for (int j = 0; j < length; j++){
            currentHashTable[strs[i][j] - 'a']++;
        };

        int anagramExisted = 0;
        for (int anagramIndex = 0; anagramIndex < numOfUniqueAnagrams; anagramIndex++){
            for (int k = 0; k < 26; k++){
                if (currentHashTable[k] == hashTable[anagramIndex][k] && (k == 25) && !anagramExisted){
                    anagramExisted = 1;
                    result[anagramIndex][groupSizeTable[anagramIndex]++] = strs[i];
                    break;
                } else if (currentHashTable[k] != hashTable[anagramIndex][k]){
                    break;
                }
            };
                
            if (anagramExisted == 1) break;
        };
    };

    (*returnSize) = numOfUniqueAnagrams;

    return result;
}

int main(){
    char* strs[] = {"eat","tea","tan","ate","nat","bat"};
    int strsSize = 6;
    int returnSize;  
    int* returnColumnSizes; 

    char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        printf("Group %d (size %d): ", i, returnColumnSizes[i]);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("\"%s\" ", result[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}