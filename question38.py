class Solution(object):
    def countAndSay(self, n):
        return self.getStr(n)
    def getStr(self,n):
        if n==1:
            return '1'
        strs=self.getStr(n-1)+'#'
        print(strs)
        j=0
        i=0
        st=''
        while i<len(strs)-1:
            char=strs[i]
            count=0
            for j in xrange(i,len(strs)):
                if strs[j]==strs[i]:
                    count+=1
                else:
                    break
            st=st+str(count)+strs[i]
        
            i=j
            print(j)
        return st
            
        """
        :type n: int
        :rtype: str
        """
        