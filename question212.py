#Implement Trie (Prefix Tree)
class Solution:
    # @param {character[][]} board
    # @param {string[]} words
    # @return {string[]}
    def findWords(self, board, words):
    #make trie
        trie={}
        for w in words:
            t=trie
            for c in w:
                if c not in t:
                    t[c]={}
                t=t[c]
            t['#']='#'
        self.res=set()
        self.used=[[False]*len(board[0]) for _ in range(len(board))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.find(board,i,j,trie,'')
        return list(self.res)
    
    def find(self,board,i,j,trie,pre):
        if '#' in trie:
            self.res.add(pre)
        if i<0 or i>=len(board) or j<0 or j>=len(board[0]):
            return
        if not self.used[i][j] and board[i][j] in trie:
            self.used[i][j]=True
            self.find(board,i+1,j,trie[board[i][j]],pre+board[i][j])
            self.find(board,i,j+1,trie[board[i][j]],pre+board[i][j])
            self.find(board,i-1,j,trie[board[i][j]],pre+board[i][j])
            self.find(board,i,j-1,trie[board[i][j]],pre+board[i][j])
            self.used[i][j]=False
# class treeNode(object):
#     def __init__(self):
#         self.children=collections.defaultdict(treeNode)
#         self.isword=False
# class Trie(object):

#     def __init__(self):
#         self.root=treeNode()
#         """
#         Initialize your data structure here.
#         """
        

#     def insert(self, word):
#         current=self.root
#         for ch in word:
#             current=current.children[ch]
#         current.isword=True
        
        
#         """
#         Inserts a word into the trie.
#         :type word: str
#         :rtype: void
#         """
        

#     def search(self, word):
#         current=self.root
#         for ch in word:
#             current=current.children.get(ch)
#             if current==None:
#                 return False
#         return current.isword
#         """
#         Returns if the word is in the trie.
#         :type word: str
#         :rtype: bool
#         """
        

#     def startsWith(self, prefix):
#         current=self.root
#         for ch in prefix:
#             current=current.children.get(ch)
#             if current==None:
#                 return False
#         return True
#         """
#         Returns if there is any word in the trie that starts with the given prefix.
#         :type prefix: str
#         :rtype: bool
#         """
        


# # Your Trie object will be instantiated and called as such:
# # obj = Trie()
# # obj.insert(word)
# # param_2 = obj.search(word)
# # param_3 = obj.startsWith(prefix)

# class Solution(object):
#     def findWords(self, board, words):
#         mark=[[0 for i in range(len(board[0]))] for i in range(len(board))]
#         trie=Trie()
#         res=[]
#         for word in words:
#             trie.insert(word)       
#         for i in range(len(board)):
#             for j in range(len(board[0])):
#                 self.getword(trie,i,j,mark,len(board),len(board[0]),"",res,board)
#         return res
#     def getword(self,trie,row,col,mark,rowLen,colLen,s,res,board):

#         mark[row][col]=1
#         s=s+board[row][col]
#         if trie.search(s)==True and (s not in res):
#             res.append(s)
#             #return
#         if row+1<rowLen and mark[row+1][col]==0:
#             self.getword(trie,row+1,col,mark,rowLen,colLen,s,res,board)
#         if row-1>=0  and mark[row-1][col]==0:
#             self.getword(trie,row-1,col,mark,rowLen,colLen,s,res,board)        
#         if col+1<colLen and mark[row][col+1]==0:
#             self.getword(trie,row,col+1,mark,rowLen,colLen,s,res,board)
#         if col-1>=0 and mark[row][col-1]==0:
#             self.getword(trie,row,col-1,mark,rowLen,colLen,s,res,board)
#         mark[row][col]=0
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """