/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head);
void reorderList(struct ListNode* head) {
    struct ListNode*p,*q,*r,*l1,*l2;
    int length=0;
    int mid=0;
    p=q=head;
    if(!head)return NULL;
    while(p)
    {
        p=p->next;
        length++;
    }
    mid=(length+1)/2;
    while(mid>1)
    {
        q=q->next;
        mid--;
    }
    p=q->next;
    q->next=NULL;
    q=head;
    r=reverse(p);
   // q->next=r;
   // return;
  //  return NULL;
    while(r&&q)
    {
        l1=q->next;
        l2=r->next;
        q->next=r;
        r->next=l1;
        q=l1;
        r=l2;
        //r=r->next;
        //q=p;
    }
    return head;
}
struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode*p,*q;
    struct ListNode* h=(struct ListNode *)malloc(sizeof(struct ListNode));
    h->next=head;
    p=q=head;
    if(!head)
        return NULL;
    while(p&&p->next)
    {
        q=p->next;
        p->next=q->next;
        q->next=h->next;
        h->next=q;
    }
    return q;
}