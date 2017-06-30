/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *p,*q,*r;
    r=p=q=head;
    int length=0;
    if(k==0)
        return head;
    if(!head)return NULL;
    while(r)
    {
        r=r->next;
        length++;
    }
    k=k%length;
    if(k==0)return head;
    while(q->next)
    {
 
        q=q->next;
        
        if(!k)
            p=p->next;
        else
            k--;
        
    }
    q->next=head;
    head=p->next;
    p->next=NULL;
    return head;
}