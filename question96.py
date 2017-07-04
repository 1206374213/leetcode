class Solution(object):
    def numTrees(self, n):
        p=[0 for i in xrange(n+1)]
        p[0]=1
        p[1]=1
        for i in xrange(2,n+1):
            for j in xrange(0,i):
                p[i]+=p[j]*p[i-1-j]
        return p[n]
        """
        :type n: int
        :rtype: int
        """
        