/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
 struct ListNode*p,*q,*r;
 p=head;
 while(p&&p->next)
 {
     q=p->next;
     if(p==head)
     {
         p->next=q->next;
         q->next=p;
         head=q;
      
     }
     else
     {
         p->next=q->next;
         q->next=p;
         r->next=q;
     }
        r=p;
        p=p->next;
 }
 return head;
}