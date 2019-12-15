
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>

bool canJump(int* nums, int numsSize);

int main()
{
    int nums[] = {3, 2, 1, 0, 4};
    int ret = canJump(nums, sizeof(nums)/sizeof(nums[0]));
    printf("ret = %d\n", ret);
}

bool canJump(int* nums, int numsSize){

    int * dp = malloc(sizeof(int) * (numsSize + 1));

    for (int i = 0; i < numsSize + 1 ; i++)
    {
        dp[i] = -1;
    }


    bool ret = false;

    dp[1] = true;
    dp[0] = true;

    if (numsSize == 1)
    {
        ret = true;
        goto _out;
    }

    for (int dp_size = 2; dp_size <= numsSize; dp_size++)
    {

        int k = nums[numsSize -dp_size];

        if (!k)
        {
            dp[dp_size] = false;
            continue;
        }

        int i;

        for(int i = 1; i<=k; i++)
        {
            if (i >= (dp_size - 1))
            {
                ret = true;
                dp[dp_size] = true;
                break;
            }


            if (dp[dp_size - i] == true)
            {

                dp[dp_size] == dp[dp_size - i];
                break;
            }

        }

        if ( i > k)
        {
            dp[dp_size] = false;
        }
    }

_out:

    free(dp);

    return dp[numsSize];

}


