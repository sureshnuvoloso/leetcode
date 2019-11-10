int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    int prev = 0;
    int s = 1;
    
    if (!numsSize)
    {return 0;}
    
    for (i = 1; i<numsSize; i++)
    {
        if (nums[i] != nums[prev])
        {
            nums[s] = nums[i];
            s++;
        }
        prev = i;
               
    }
    return s;

}
