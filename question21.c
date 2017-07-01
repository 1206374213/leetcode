/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode*p,*r,*q,*newHead;
    newHead=(struct ListNode*)malloc(sizeof(struct ListNode));
    r=newHead;
    p=l1;
    q=l2;
    r->next=NULL;
    
    while(p&&q){
        if(p->val<q->val){
        r->next=p;
        p=p->next;
        r=r->next;
        }
        else{
        r->next=q;
        q=q->next;
        r=r->next;   
        }
    }
    while(p){r->next=p;p=p->next;r=r->next;}
    while(q){r->next=q;q=q->next;r=r->next;}
    return newHead->next;
}