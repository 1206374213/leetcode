/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool judge(struct TreeNode*left,struct TreeNode *right);
bool isSymmetric(struct TreeNode* root) {
      if(!root)return true;
      return judge(root->left,root->right);
}
bool judge(struct TreeNode*left,struct TreeNode *right){
    if(!left&&!right)return true;
    if(left&&right)
    {
        return (left->val==right->val)&&judge(left->left,right->right)&&judge(left->right,right->left);
    }
    return false;
}