class Solution(object):
    def minimumTotal(self, triangle):
        temp=[]
        if len(triangle)==0 or len(triangle[0])==0:
            return 0
        temp.append(triangle[0])
        for i in xrange(1,len(triangle)):
            re=[]
           
            for j in xrange(len(triangle[i])):
                xmin=0x7fffffff
                if j>=0 and j<len(triangle[i-1]):
                    xmin=temp[i-1][j]
                if j-1>=0 and j-1<len(triangle[i-1]):
                    if xmin>temp[i-1][j-1]:
                        xmin=temp[i-1][j-1]
                xmin=xmin+triangle[i][j]
                re.append(xmin)
            temp.append(re[:])
        return min(temp[-1])
                    
                    
                
        
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        