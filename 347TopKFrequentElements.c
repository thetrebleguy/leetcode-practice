#include <stdio.h>
#include <stdlib.h>

// inefficient LOL

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
};

void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeArray(int** arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1][2], R[n2][2];

    // Copy data
    for (int i = 0; i < n1; i++) {
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (int j = 0; j < n2; j++) {
        R[j][0] = arr[m + 1 + j][0];
        R[j][1] = arr[m + 1 + j][1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i][1] >= R[j][1]) {  // Sort by column 1 (descending)
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        } else {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }

    // Copy remaining
    while (i < n1) {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}

void mergeSortArray(int** arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortArray(arr, l, m); 
        mergeSortArray(arr, m + 1, r);
        mergeArray(arr, l, m, r);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* topK = malloc((numsSize) * sizeof(int));
    mergeSort(nums, 0, numsSize - 1);

    // make a hash table
    int** hashTable = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++){
        hashTable[i] = (int*)malloc(2 * sizeof(int));
        hashTable[i][0] = 0;
        hashTable[i][1] = 0;
    };

    // put it into the hash table
    int numOfUniqueElements = 0;
    for (int i = 0; i < numsSize; i++){
        if (i == 0){
            hashTable[0][0] = nums[0];
            hashTable[0][1]++;
        } else if (hashTable[numOfUniqueElements][0] == nums[i]){
            hashTable[numOfUniqueElements][1]++;
        } else {
            numOfUniqueElements++;
            hashTable[numOfUniqueElements][0] = nums[i];
            hashTable[numOfUniqueElements][1]++;
        }
    };

    // i need to somehow sort the hashmap
    mergeSortArray(hashTable, 0, numOfUniqueElements);

    int* result = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = hashTable[i][0];
    };

    for (int i = 0; i <= numOfUniqueElements; i++){
        free(hashTable[i]);
    };
    free(hashTable);
    (*returnSize) = k;
    return result;
}

int main(){
    int numOfElements, k, returnSize;
    scanf("%d %d", &numOfElements, &k); getchar();

    int* nums = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &nums[i]); getchar();
    };

    nums = topKFrequent(nums, numOfElements, k, &returnSize);
    for (int i = 0; i < returnSize; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}