# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        if root==None:
            return []
        last=0
        rear=-1
        front=-1
        queue=[]
        result=[]
        temp=[]
        queue.append(root)
        rear+=1
        while front<rear:
            t=queue.pop(0)
            front+=1
            temp.append(t.val)
            if t.left!=None:
                queue.append(t.left)
                rear+=1
            if t.right!=None:
                queue.append(t.right)
                rear+=1
            if last==front:
                result.append(temp[:])
                temp=[]
                last=rear
        return   result    
        
        
        
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """