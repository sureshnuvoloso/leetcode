#include <malloc.h>
#include <stdio.h>

#define min(a, b)   ((a) < (b)) ? (a) : (b)

int coinChange(int* coins, int coinsSize, int amount);

int main()
{
    int coins[] = {186,419, 83, 408};
    int amount = 6249;
    coinChange(coins, sizeof(coins), amount);
    return 0;
}

int coinChange_helper(int* coins, int coinsSize, int amount, int *dp);

int coinChange(int* coins, int coinsSize, int amount)
{
    int * dp  = calloc(amount + 1, sizeof(int));
    int ret = coinChange_helper(coins, coinsSize, amount, dp);
    free(dp);
    return ret;

}

int coinChange_helper(int* coins, int coinsSize, int amount, int *dp)
{

    int min_cnt = -1;

    if (amount < 0)
    {
        return -1;
    }

    if (amount == 0)
    {
        return 0;
    }

    if (dp[amount])
    {
        return dp[amount];
    }

    for (int i = 0; i < coinsSize; i++)
    {
        if (amount == coins[i])
        {
            return 1;
        }
        else if (coins[i] < amount)
        {
            int tcnt = coinChange_helper(coins, coinsSize, amount - coins[i], dp);

            if (tcnt > 0)
            {
                int cnt = tcnt + 1;

                if (min_cnt < 0)
                {
                    min_cnt = cnt;
                }
                else
                {
                    min_cnt = min(min_cnt, cnt);
                }
            }
        }
    }


    if (min_cnt > 0)
    {
        dp[amount] = min_cnt;
        return min_cnt;
    }

    return -1;

}


