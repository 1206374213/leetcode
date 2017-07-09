/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
  if(!root)return 0;
  struct TreeNode *queue[100000];
  struct TreeNode *p;
    int front=0;
    int rear=0;
    int last=1;
    int level=1;
    queue[rear++]=root;
    while(front!=rear)
    {
        p=queue[front++];
                if(!p->left&&!p->right)
            return level;
        if(p->left)
            queue[rear++]=p->left;
        if(p->right)
            queue[rear++]=p->right;
        if(last==front)
        {
            
            last=rear;
            level++;
        }

    }
    return level;
}