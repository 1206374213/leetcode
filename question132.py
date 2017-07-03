class Solution(object):
    def minCut(self, s):
        if len(s)==0:
            return NULL
        p=[[False for i in xrange(len(s))]for i in xrange(len(s))]
        result=[]
        for i in xrange(len(s)):
            for j in xrange(len(s)):
                if i>=j:
                    p[i][j]=True
        for k in xrange(1,len(s)):
            for i in xrange(len(s)):
                j=i+k
                if j<len(s):
                    if s[i]==s[j]:
                        p[i][j]=p[i+1][j-1]
                    else:
                        p[i][j]=False
        count=[0 for i in xrange(len(s))]
        count[0]=0
        for i in xrange(1,len(s)):
            min=0x7fffffff
            if p[0][i]==True:
                count[i]=0
            else:
                for j in xrange(1,i+1):
                    if p[j][i]:
                        if min>1+count[j-1]:
                            min=1+count[j-1]
                count[i]=min
        return count[len(s)-1]

        """
        :type s: str
        :rtype: int
        """
        