#include <stdio.h>

#define min(a, b)  ((a) < (b)) ? (a) : (b);
#define max(a, b)  ((a) > (b)) ? (a) : (b);

    

int maxProfit(int* prices, int pricesSize){

    int profit = 0;
    int i = 0;
    unsigned int price_low_global = (unsigned int)-1;
    int max_profit = 0;

    while (i < pricesSize -1)
    {
        while ((i < pricesSize -1) && (prices[i + 1] < prices[i])) 
        {
            i++;
        }

        int price_low = prices[i];

        price_low_global = min(price_low, price_low_global);

        while ((i < pricesSize -1) && (prices[i + 1] > prices[i])) 
        {
            i++;
        }
        int price_high = prices[i];

        profit = price_high - price_low_global;

        max_profit = max(profit, max_profit);

        i++;
    }

    return max_profit;

}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};

    int profit = maxProfit(arr, sizeof(arr)/sizeof(arr[0]));

    printf ("profit:%d\n", profit);

}


