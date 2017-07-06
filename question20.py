class Solution(object):
    def isValid(self, s):
        stack=[]
        if len(s)==0:
            return True
        if len(s)==1:
            return False
        stack.append(s[0])
        i=1
        while i<len(s):
            if s[i]=='{' or s[i]=='[' or s[i]=='(':
                stack.append(s[i])
                i+=1
            else:
                
                if(len(stack)!=0):
                    notation=stack.pop()
                else:
                    
                    return False
                if( notation=='(' and s[i]==')' ) or ( notation=='{' and s[i]=='}' ) or ( notation=='[' and s[i]==']' ):
                    i+=1
                    continue
                else:
                    return False
            
        if(len(stack)==0):
            return True
        else:
            return False
        """
        :type s: str
        :rtype: bool
        """
        