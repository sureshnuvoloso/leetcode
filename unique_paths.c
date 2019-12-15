#include <stdio.h>
#include <malloc.h>
int uniquePaths(int m, int n);

int main()
{
    printf("%d\n",uniquePaths(2,2));
}


int uniquePaths_helper(int m, int n, int ** dp);

int uniquePaths(int m, int n)
{

    int **dp = malloc(sizeof(int *) * m);

    for (int i = 0; i < m; i++)
    {
        dp[i] = malloc(sizeof(int) * n);

    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;

        }         
    }


    return (uniquePaths_helper(m, n, dp));
}

int uniquePaths_helper(int m, int n, int **dp){

    if (m ==1 || n == 1)
    {
        dp[m - 1][n - 1] = 1;
        return 1;
    }

    if (dp[m - 1][n - 1] != -1)
    {
        return dp[m - 1][n - 1];
    }

    dp[m - 1][n - 1] =  uniquePaths(m - 1, n ) + uniquePaths(m , n -1);
    return dp[m - 1][n - 1];
}


