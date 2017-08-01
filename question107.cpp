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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> stack;
        vector<int>temp;
        if(!root)return res;
        int rear=1;
        int front=0;
        int last=1;
        stack.push_back(root);
        while(stack.size()>0)
        {
            TreeNode *t=stack.front();
            stack.pop_front();
            temp.push_back(t->val);
            front++;
            if(t->left)
            {
                stack.push_back(t->left);
                rear++;
            }
                
            if(t->right)
            {
                stack.push_back(t->right);
                rear++;
            }
            if(last==front)
            {
                last=rear;
                res.insert(res.begin(),temp);
                temp.clear();
            }
                
        }
return res;
        
    }
};