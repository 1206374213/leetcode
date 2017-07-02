class Solution(object):
    def candy(self, ratings):
        nums=[1 for i in range(len(ratings))]
        for i in range(1,len(ratings)):
            if ratings[i]>ratings[i-1]:
                nums[i]=nums[i-1]+1
        for i in range(len(ratings)-1,0,-1):
            if ratings[i]<ratings[i-1] and nums[i]>=nums[i-1]:
                nums[i-1]=nums[i]+1
        total=0
        for i in range(len(ratings)):
            total+=nums[i]
        print(nums)
        return total
        """
        :type ratings: List[int]
        :rtype: int
        """
        