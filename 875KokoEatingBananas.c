#include <stdio.h>
#include <stdlib.h>

// i think me know what to do i already drew on paper
// just gotta try coding it tmrw

int minEatingSpeed(int* piles, int pilesSize, int h) {
    // what can i even do lol

};

int main(){
    int numOfElements, hours;
    scanf("%d", &numOfElements); getchar();

    int* piles = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &piles[i]); getchar();
    };

    scanf("%d", &hours); getchar();

    int minHours = minEatingSpeed(piles, numOfElements, hours);
    return 0;
};