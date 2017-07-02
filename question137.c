int singleNumber(int* nums, int numsSize) {
    int one=0,two=0,three=0;
    int i=0;
    while(i<numsSize)
    {
        two|=one&nums[i];
        one^=nums[i];
        three=~(one&two);
        one&=three;
        two&=three;
        i++;
    }
    return one;
}