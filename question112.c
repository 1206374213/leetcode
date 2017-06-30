/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isExist(struct TreeNode *root,int sum);
bool hasPathSum(struct TreeNode* root, int sum) {
    return root&&isExist(root,sum);
}
bool isExist(struct TreeNode *root,int sum){
    if(!root)return false;
    if(sum-root->val==0)
    {
        if(!root->left&&!root->right)
        return true;
    }
            return isExist(root->left,sum-root->val)||isExist(root->right,sum-root->val);
}