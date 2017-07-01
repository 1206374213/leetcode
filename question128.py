class Solution(object):
    def longestConsecutive(self, nums):
        dict={}
        max=0;
        for i in xrange(len(nums)):
            dict[nums[i]]=True
        for i in xrange(len(nums)):
            count=0
            if nums[i] not in dict:
                continue
            else:
                count+=1
                del dict[nums[i]]
                left=nums[i]-1
                right=nums[i]+1
                while left in dict:
                    count+=1
                    del dict[left]
                    left-=1
                while right in dict:
                    print(right)
                    count+=1
                    del dict[right]
                    right+=1
            if count>max:
                max=count
        return max
   # def getMAX(self,nums,num,dict):
   #     if num not in dict or dict[num]==False:
   #         return 0
   #     else:
   #         dict[num]=False
    #        return 1+self.getMAX(nums,num-1,dict)+self.getMAX(nums,num+1,dict)
                
        
        """
        :type nums: List[int]
        :rtype: int
        """
        