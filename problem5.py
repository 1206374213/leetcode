# Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

# Example:

# Input: "babad"

# Output: "bab"

# Note: "aba" is also a valid answer.
# Example:

# Input: "cbbd"

# Output: "bb"
class Solution(object):
    def longestPalindrome(self, s):
        #dynamic programming
        # length=len(s)
        # maxLen=0
        # maxLeft=0
        # maxRight=0
        # mark=[[False for i in range(len(s))]for i in range(len(s))]
        # for i in xrange(length):
        #     for j in xrange(length):
        #         if i>=j:
        #             mark[i][j]=True
        #         else:
        #             mark[i][j]=False
        # for i in range(1,length):
        #     for j in range(length):
        #         if j+i>=length:
        #             break
        #         if s[j]!=s[j+i]:
        #             mark[j][j+i]=False
        #         else:
        #             mark[j][j+i]=mark[j+1][j+i-1]
        #         if mark[j][j+i]==True:
        #             if i>maxLen:
        #                 maxLen=i
        #                 maxLeft=j
        #                 maxRight=j+i
        # return s[maxLeft:maxRight+1]
        #
        mx=0
        index=0
        i=0
        maxMark=0;
        maxId=0
        prestr='#'+'#'.join(s)+'#'
        mark=[0]*len(prestr)
        while i< len(prestr):
            if i<mx:
                mark[i]=min(mark[2*index-i],mx-i)
            else:
                mark[i]=1
            while i-mark[i]>=0 and i+mark[i]<len(prestr) and prestr[i-mark[i]]==prestr[i+mark[i]]:
                mark[i]+=1
            if mx<mark[i]+i:
                mx=mark[i]+i
                index=i
            if mark[i]>maxMark:
                maxMark=mark[i]
                maxId=index
            i+=1
        print(prestr)
        print(mark)
        return prestr[maxId-maxMark+1:maxId+maxMark-1].replace('#','')
        
        
        
        
        
        
        """
        :type s: str
        :rtype: str
        """
        