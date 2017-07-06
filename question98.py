# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        p=[]
        self.preOrder(root,p)
        if len(p)==0:
            return True
        temp=p[0]
        for i in xrange(1,len(p)):
            if p[i]<=temp:
                return False
            else:
                temp=p[i]
        return True
    def preOrder(self,root,p):
        if root==None:
            return
        self.preOrder(root.left,p)
        p.append(root.val)
        self.preOrder(root.right,p)
        """
        :type root: TreeNode
        :rtype: bool
        """
        