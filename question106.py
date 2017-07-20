/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *getNode(int *inOrder,int from1,int to1,int *postOrder,int from2,int to2);
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    return getNode(inorder,0,inorderSize-1,postorder,0,postorderSize-1);
}
struct TreeNode *getNode(int *inOrder,int from1,int to1,int *postOrder,int from2,int to2){
    struct TreeNode * tr=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int j=0;
    printf("%d,%d,%d,%d\n",from1,to1,from2,to2);
    if(from1<=to1)
    {
        for (j=from1;;j++)
            if(inOrder[j]==postOrder[to2])
                break;
        tr->val=postOrder[to2];
        tr->left=getNode(inOrder,from1,j-1,postOrder,from2,from2+j-from1-1);
        tr->right=getNode(inOrder,j+1,to1,postOrder,from2+j-from1,to2-1);
        return tr;
    }
    else
        return NULL;
}