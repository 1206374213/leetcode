int removeDuplicates(int* nums, int numsSize) {
    int i,j;
    if(numsSize==0)
        return 0;
    i=j=0;
    while(j<numsSize)
    {
        if(nums[j]==nums[i])
            j++;
        else
        
        nums[++i]=nums[j++];
        
    }
    return i+1;
}