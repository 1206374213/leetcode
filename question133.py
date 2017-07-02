class Solution(object):
    def singleNumber(self, nums):
        ans=0
        for i in xrange(len(nums)):
            ans^=nums[i]
        return ans