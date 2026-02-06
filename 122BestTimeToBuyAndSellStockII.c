#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;

    for (int i = 0; i < pricesSize - 1; i++){
        if (prices[i] >= prices[i+1]){
            continue;
        } else {
            int buy = prices[i];

            // find the max peak
            while (i < (pricesSize - 1) && (prices[i] < prices[i + 1])){
                i++;
            };

            int sell = prices[i];
            profit += (sell - buy);
        };
    };

    return profit;
}

int main(){
    int numOfPrices;
    scanf("%d", &numOfPrices); getchar();

    int* prices = malloc(sizeof(int) * numOfPrices);
    for (int i = 0; i < numOfPrices; i++){
        scanf("%d", &prices[i]); getchar();
    };

    printf("%d\n", maxProfit(prices, numOfPrices));
    return 0;
}