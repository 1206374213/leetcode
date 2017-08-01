/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int i=-0x7ffffff;
        getNodeVal(root,i);
        return i;
    }
    int getNodeVal(TreeNode* root,int &max){
         
        if(!root)return 0;
        int left,right;
        left=right=-0x7ffffff;
        if(root->left)
        left=getNodeVal(root->left,max);
        if(root->right)
        right=getNodeVal(root->right,max);
        int temp=right>left?right:left;
        if(left+root->val>temp)
            temp=left+root->val;
        if(right+root->val>temp)
            temp=right+root->val;
        if(root->val>temp)
            temp=root->val;
        if(right+left+root->val>temp)
            temp=right+left+root->val;
        if(temp>max)
            max=temp;
       // cout<<temp<<endl;
       
        if(left<0&&right<0)
            return root->val;
        if(left>=0&&right>=0)
        {
            return left+root->val>right+root->val?left+root->val:right+root->val;
        }
        if(left>=0)
            return left+root->val;
        if(right>=0)
            return right+root->val;
        
    }
};