
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool canJump(int* nums, int numsSize);

int main()
{
    int nums[] = {3, 2, 1, 0, 4};
    int ret = canJump(nums, sizeof(nums)/sizeof(nums[0]));
    printf("ret = %d\n", ret);
}



bool canJump(int* nums, int numsSize){

    if (numsSize == 1)
    {
        assert(0);
        return true;
    }

    int k = nums[0];

    for(int i = 1;  i<=k; i++)
    {
        if (i >= (numsSize - 1))
        {
            assert(0);
            return true;
        }
        bool ret = canJump(&nums[i], numsSize - i);

        if (ret)
        {
            assert(0);
            return ret;
        }

    }

    return false;

}


