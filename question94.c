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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
     struct TreeNode *stack[1024];
    struct TreeNode * t;
    int size=0;
    int p[1024];
    int i=0;
     int top=0;
     if(!root)
     {
         *returnSize=0;
         return NULL;
     }
   //  stack[top++]=root;
    t=root;
    while(t||top)
    {
       // t=stack[top-1];
        if(t)
        { stack[top++]=t;
            t=t->left;
           
        }
        else
        {
            t=stack[--top];
           // printf("%d",t->val);
            p[size++]=t->val;
            t=t->right;
        }   
    }
    int *res=(int *)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
        res[i]=p[i];
    *returnSize=size;
    return res;
}