class Solution(object):
    def numDistinct(self, s, t):
        sLength=len(s)
        tLength=len(t)
        if(sLength==0):
            return 0
        tag=[[0 for x in range(sLength+1)] for x in range(tLength+1)]
        for i in range(tLength+1):
            tag[i][0]=0
        for i in range(sLength+1):
            tag[0][i]=1
        for i in range(1,tLength+1):
            for j in range(1,sLength+1):
                if s[j-1]==t[i-1]:
                    tag[i][j]=tag[i-1][j-1]+tag[i][j-1]
                else:
                    tag[i][j]=tag[i][j-1]
        return tag[tLength][sLength]
        #Slength = len(s)
        #Tlength = len(t)
    #     count = 0
    #     if tIndex==len(t):
    #         return 1
    #     if sIndex==len(s):
    #         return 0
    #     for i in range(sIndex,len(s)):
    #         if s[i]==t[tIndex]:
    #           # count+
    #             flag=self.getNums(s,i+1,t,tIndex+1)
    #             if flag==0:
    #                 return count
    #             else:
    #                 count+=flag
    #     return count
    # def numDistinct(self, s, t):
    #     if len(s)==0:
    #         return 0
    #     return self.getNums(s,0,t,0)
        
    
        