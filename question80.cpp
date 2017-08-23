Remove Duplicates from Sorted Array II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j,mark;
        mark=0;
        j=0;
        i=-1;
        int size=nums.size();
        if(size<=2)
            return size;
        while(j<size)
        {
            if(i==-1)
            {
                    nums[++i]=nums[j++];
                    mark++;
                    continue;
            }
            if(nums[i]==nums[j])
            {
                if(mark==2)
                {
                    j++;
                }
                else
                {
                    nums[++i]=nums[j++];
                    mark++;
                }
            }
            else
            {
                mark=1;
                nums[++i]=nums[j++];
            }
            
            
        }
        return i+1;
    }
};