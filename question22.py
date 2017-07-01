class Solution(object):
   def generateParenthesis(self, n):
       def getParenthesis(p,left,right,result=[]):
           if left:getParenthesis(p+'(',left-1,right)
           if right>left:getParenthesis(p+')',left,right-1)
           if not right: result+=p,
           return result
       return getParenthesis('',n,n)