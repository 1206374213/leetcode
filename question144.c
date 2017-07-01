/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct st{
    struct TreeNode *data[10000];
    int top;
   // int end;
}Stack;
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    Stack stack;
    stack.top=0;
   // stack.end=0;
    if(!root)
    {
        *returnSize=0;
        return NULL;
    }
    int p[10000];
    int i=0;
    stack.data[stack.top++]=root;
    while(stack.top>0)
    {
        struct TreeNode *t=stack.data[--stack.top];
        p[i++]=t->val;
        if(t->right)
            stack.data[stack.top++]=t->right;
        if(t->left)
            stack.data[stack.top++]=t->left;
        
    }
    int * result=(int *)malloc(sizeof(int)*i);
    int j;
    for (j=0;j<i;j++)
        result[j]=p[j];
    *returnSize=i;
    return result;
}