/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseList(struct ListNode* head,int k);
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    struct ListNode *q;
    q=(struct ListNode*)malloc(sizeof(struct ListNode));
    q->next=head;
    head=q;
    //=head;
    while((q=reverseList(q,k))!=NULL);
    //q-next=NULL;
    //free(q);
    
    return head->next;
    
}
struct ListNode* reverseList(struct ListNode* head,int k)
{
    struct ListNode *p,*q,*r;
    p=head;
    int i=0;
    if(p==NULL)
    return NULL;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    if(i<k)return NULL;
    else
    {
        p=head;
        q=p->next;
        r=q->next;
        while(k>1)
        {
            q->next=r->next;
            r->next=p->next;
            p->next=r;
            r=q->next;
            k--;
            
        }
        //head=q;
        return q;
    }
}