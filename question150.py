import math
class Solution(object):
    #def isNumber(self,str):
        
    def evalRPN(self, tokens):
        stack=[]
        op1=0
        op2=0
        for i in xrange(len(tokens)):
            if tokens[i]=='+' or tokens[i]=='-' or tokens[i]=='*' or tokens[i]=='/':
                
                op2=int(stack.pop())
                op1=int(stack.pop())
                if tokens[i]=='+':
                    stack.append(str(op1+op2))
                elif tokens[i]=='-':
                    stack.append(str(op1-op2))
                elif tokens[i]=='*':
                    stack.append(str(op1*op2))
                else:
                    if op1*op2<0 and op1%op2!=0:
                        stack.append(str(int(op1/op2)+1))
                    
                    else:
                        stack.append(str(int(op1/op2)))
                    print(str(int(op1/op2)))
            else:
                stack.append(tokens[i])
        return int(stack.pop())
        