int removeElement(int* nums, int numsSize, int val) {
    int i,j;
    if(numsSize==0)
        return 0;
    
    i=j=0;
    while(i<numsSize)
    {
        if(nums[i]==val)
            i++;
        else
        //{
            nums[j++]=nums[i++];
        //}
    }
    return j;
}