class Solution(object):
    def partition(self, s):
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
     #   print(p)
        self.DFS(s,0,p,result,[])
        return result
       
    def DFS(self,s,index,p,result,temp):
        if index==len(s):
            result.append(temp[:])
            
            return
        #print(index)
        for i in xrange(index,len(s)):
            if p[index][i]==True:
                temp.append(s[index:i+1])
                self.DFS(s,i+1,p,result,temp)
                temp.pop()
        """
        :type s: str
        :rtype: List[List[str]]
        """
        