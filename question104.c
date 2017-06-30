/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int DEP(struct TreeNode *node);
int maxDepth(struct TreeNode* root) {
    if(!root)return 0;
    return DEP(root);
}
int DEP(struct TreeNode *node){
    if(!node)
    return 0;
    return max(DEP(node->left)+1,DEP(node->right)+1);
}
int max(int a,int b)
{
    return a>b?a:b;
}