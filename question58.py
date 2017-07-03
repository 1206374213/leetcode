class Solution(object):
    def lengthOfLastWord(self, s):
        i=0
        length=0
        last=0
        while i<len(s):
            if length!=0:
                last=length
            #last=length
            while i<len(s) and s[i]==' ':
                #last=length
                length=0
                i+=1
            if i<len(s):
                #length+=1
                while i<len(s) and s[i]!=' ':
                    i+=1
                    length+=1
                    last=length
        return last
        """
        :type s: str
        :rtype: int
        """
        