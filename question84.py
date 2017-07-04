class Solution(object):
    def largestRectangleArea(self, heights):
        heights.append(-1)
        ans=0
        stack=[]
        i=0
        while i <len(heights):
            if len(stack)==0 or heights[stack[-1]]<=heights[i]:
                stack.append(i)
                i+=1
            else:
                top=stack.pop()
                area=0
                if len(stack)==0:
                    area=i*heights[top]
                else:
                    area=heights[top]*(i-1-stack[-1])
                print(area)
                ans=max(ans,area)
        return ans
        
        
        """
        :type heights: List[int]
        :rtype: int
        """
        