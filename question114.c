/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode *stack[1000];
    struct TreeNode *q;
    q=NULL;
    ///head=NULL;
    int top=-1;
    if(!root)return;
    stack[++top]=root;
    while(top!=-1)
    { 
        if(!q)
        {
            q=stack[top--];
            
            
        }
        else
        {
            q->right=stack[top--];
            q->left=NULL;
            q=q->right;
           
            
        }
            if(q->right)
                stack[++top]=q->right;
            if(q->left)
                stack[++top]=q->left;
        
    }
    
}