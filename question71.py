class Solution(object):
    def simplifyPath(self, path):
        if len(path)==0:
            return ''
        p=[]
        i=0
        p.append(path[0])
        while i<len(path):
            end=i
            while end<len(path) and path[end]!='/':
                end+=1
            if path[i:end]=='' or path[i:end]=='.':
                i+=1
                continue
            else:
                if path[i:end]=='..':
                    if(len(p)>1):
                        p.pop()
                    i+=1
                else:
                    p.append(path[i:end])
                    i=end+1
        result=''
        for str in p:
            if result=='':
                result+=str
            else:
                result+=str+r'/'
        #print(result)
        if len(result)==1:
            return '/'
        return result[0:len(result)-1]
                    
                    
        
        """
        :type path: str
        :rtype: str
        """
        