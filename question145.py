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
#define MAX 1000
typedef struct stack{
    struct TreeNode *data[MAX];
    int top;
}Stack;
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    Stack stack;
    stack.top=0;
    if(!root)
    return NULL;
    stack.data[stack.top++]=root;
    int i=0;
    int p[10000];
    struct TreeNode *cur,*pre;
    cur=root;
    while(stack.top>0)
    {
        while(cur!=NULL&&cur->left)
        {
             stack.data[stack.top++]=cur->left;
             cur=cur->left;
        }
        cur=stack.data[stack.top-1];
        if(cur->right&&pre!=cur->right)
        {
             stack.data[stack.top++]=cur->right;
             cur=cur->right;
        }
        else
        {
             p[i++]=cur->val;
             printf("%d",cur->val);
             pre=cur;
             cur=NULL;
             stack.top--;
        }
    }
    int * result=(int *)malloc(sizeof(int)*i);
    *returnSize=i;
    for(i=0;i<*returnSize;i++)
    result[i]=p[i];
    return result;
}