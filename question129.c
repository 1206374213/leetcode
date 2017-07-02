/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
    if(!root)return 0;
    return getNumber(root,root->val);
}
int getNumber(struct TreeNode *tr,int number)
{
    //if(!tr)return 0;
    if(tr->left&&tr->right)
        return getNumber(tr->left,number*10+tr->left->val)+getNumber(tr->right,number*10+tr->right->val);
    else if(tr->left)
        return getNumber(tr->left,number*10+tr->left->val);
    else if(tr->right)
        return getNumber(tr->right,number*10+tr->right->val);
    else return number;
        
}