/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// struct TreeNode *BST(struct ListNode* from,struct ListNode*to);
// struct ListNode * findTail(struct ListNode* p);
// struct ListNode* getNode(struct ListNode*from,struct ListNode *to);
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(!head)return NULL;
    struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
     struct ListNode *p,*q,*r;
    if(!head->next)
    {
        node->val=head->val;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    p=q=r=head;
    while(q->next&&q->next->next)
    {
        r=p;
        p=p->next;
        q=q->next->next;
    }
    q=p->next;
    p->next=NULL;
    r->next=NULL;
    node->val=p->val;
    if(head!=p)node->left=sortedListToBST(head);
    else node->left=NULL;
    node->right=sortedListToBST(q);
    return node;
}
// struct TreeNode *BST(struct ListNode* from,struct ListNode*to)
// {
    
//     struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode*));
//     struct ListNode *t1,*t2,*p;
//     p=getNode(from,to);
    
//      if(!p)
//          return NULL;
//      node->val=p->val;
    
//      t1=findTail(from);
//      t2=findTail(p->next);
//     printf("%d",t1->val); 
//     printf("%d",t2->val);
//      node->left=BST(from,t1);
//      node->right=BST(p->next,t2);
//     return node;
// }
// struct ListNode * findTail(struct ListNode* p)
// {
//     if(!p)return NULL;
//     while(p->next)
//         p=p->next;
//     return p;
    
// }
// struct ListNode* getNode(struct ListNode*from,struct ListNode *to){
//     struct ListNode*p,*q,*r;
//     p=q=from;
//     if(!from||!to)return NULL;
//     if(from==to)
//         return from;
//     r=NULL;
//     while(q!=to&&q->next!=to)
//     {
//         r=p;
//         p=p->next;
//         q=q->next->next;
//     }
//     if(!r)
//         return p;
//     else
//     {
//         r->next=NULL;
//         return p;
//     }
//     //return p;
        
// }