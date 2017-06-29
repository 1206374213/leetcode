# You are climbing a stair case. It takes n steps to reach to the top.

# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

# Note: Given n will be a positive integer.
class Solution(object):
    def climbStairs(self, n):
        mark=[1]*(n+1)
        for i in xrange(1,n+1):
            if i>=2:
                mark[i]=mark[i-1]+mark[i-2]
            else:
                mark[i]=1
        return mark[n]
    #     return self.getWays(n)
    # def getWays(self,n):
    #     if n==0:
    #         return 1
    #     if n<0:
    #         return 0
    #     else:
    #         return self.getWays(n-1)+self.getWays(n-2)
        """
        :type n: int
        :rtype: int
        """
        