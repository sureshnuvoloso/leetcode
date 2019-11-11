#include <stdio.h>

int maxProfit(int* prices, int pricesSize){

    int profit = 0;
    int i = 0;

    while (i < pricesSize -1)
    {
        while (prices[i + 1] < prices[i] && (i < pricesSize -1))
        {
            i++;
        }

        int price_low = prices[i];

        while (prices[i + 1] > prices[i] && (i < pricesSize -1))
        {
            i++;
        }
        int price_high = prices[i];

        profit += price_high - price_low;

        i++;
    }

    return profit;

}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};

    int profit = maxProfit(arr, sizeof(arr)/sizeof(arr[0]));

    printf ("profit:%d\n", profit);

}


