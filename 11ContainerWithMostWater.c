#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int measureArea(int height1, int height2, int width){
    int height = height1 > height2 ? height2 : height1;
    int area = height * width;
    return area;
};

int maxArea(int* height, int heightSize) {
    int maxVolume = 0;
    int i = 0, j = heightSize - 1;
    
    while (i < j) {
        int currentArea = measureArea(height[i], height[j], j - i);
        if (currentArea > maxVolume) maxVolume = currentArea;
        
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    
    return maxVolume;
}

int main(){
    int numOfElements;
    scanf("%d", &numOfElements);

    int* height = malloc(numOfElements * sizeof(int));
    for (int i = 0; i < numOfElements; i++){
        scanf("%d", &height[i]); getchar();
    };

    int result = maxArea(height, numOfElements);
    printf("%d\n", result);
    return 0;
}