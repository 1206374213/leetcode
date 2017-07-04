class Solution(object):
    def maximalRectangle(self, matrix):
        ans=0
        if len(matrix)<=0 or len(matrix[0])<=0:
            return 0
        p=[[0 for i in xrange(len(matrix[0]))]for i in xrange(len(matrix))]
        for j in xrange(len(matrix[0])):
            temp=0
            for i in xrange(len(matrix)):
                if matrix[i][j]=='1':
                    temp+=1
                    p[i][j]=temp
                else:
                    p[i][j]=0
                    temp=0
        for i in xrange(len(matrix)):
            temp=self.largestRectangleArea(p[i][:])
            ans=max(ans,temp)
        return ans
            
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
                #print(area)
                ans=max(ans,area)
        return ans
        
        
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        