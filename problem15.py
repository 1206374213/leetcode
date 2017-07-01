class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        return self.getResult(nums)
    def getResult(self,nums):
        result=[]
        for i in range(len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            begin,end=i+1,len(nums)-1
            while begin<end:
                left=nums[i]+nums[begin]+nums[end]
                if left>0:
                    end-=1 
                elif left<0:
                    begin+=1
                else:
                    result.append((nums[i],nums[begin],nums[end]))
                    while begin<end and nums[begin]==nums[begin+1]:
                        begin+=1
                    while begin<end and nums[end]==nums[end-1]:
                        end-=1
                    begin+=1
                    end-=1
        return result
        
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        