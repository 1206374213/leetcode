// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * BST(int *nums,int from,int to);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
     if(numsSize == 0)
     return NULL;
     return BST(nums,0,numsSize-1);
}
struct TreeNode * BST(int *nums,int from,int to)
{
    int mid;
    if(from<=to)
    {
        mid=(from+to)/2;
        struct TreeNode *p=malloc(sizeof(struct TreeNode));
        p->val=nums[mid];
        p->left=BST(nums,from,mid-1);
        p->right=BST(nums,mid+1,to);
        return p;
    }
    else
    return NULL;
}