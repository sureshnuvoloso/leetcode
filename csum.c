
#include <stdio.h>
#include <malloc.h>
int combinationSum4(int* nums, int numsSize, int target);


int main()
{
    int target = 32;
    int nums[] = {4, 2, 1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    int ret = combinationSum4(nums, numsSize, target);

    printf("ret:%d", ret);
    return 0;

}


int csum(int *nums, int numsSize, int target, int *dp);

int combinationSum4(int* nums, int numsSize, int target){

    int *dp = malloc(sizeof(int) * (target + 1));

    for(int i = 0; i< target + 1; i++)
    {
        dp[i] = -1;
    }

    int ret = csum(nums, numsSize, target, dp);

    free(dp);

    return ret;
}

int csum(int *nums, int numsSize, int target, int *dp)
{

    int cnt = 0;

    if (dp[target] != -1)
    {
        return dp[target];
    }

    for(int i = 0; i < numsSize; i++)
    {
        if (target == nums[i])
        {
            cnt++;
        }
        else if (target > nums[i])
        {
            int rsum = target - nums[i];

            int tcnt = dp[rsum];

            if (tcnt == -1)
            {
                tcnt = combinationSum4(nums, numsSize,  rsum);    
            }

            cnt += tcnt;
        }

    }

    dp[target] = cnt;
    return cnt;

}


