# Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
# n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two 
# lines, which together with x-axis forms a container, such that the container contains the most water.

# Note: You may not slant the container and n is at least 2.
class Solution(object):
    def maxArea(self, height):
        if len(height)<2:
            return 0
        start=0
        ans=0
        end=len(height)-1
        while start<end:
            temp=(end-start)*min(height[start],height[end])
            if temp>ans:
                ans=temp
            if height[start]<height[end]:
                start+=1
            else:
                end-=1
        return ans
        """
        :type height: List[int]
        :rtype: int
        """