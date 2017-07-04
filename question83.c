/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p,*q;
    p=q=head;
    if(!head)return head;
    while(q)
    {
        if(p->val==q->val)
        {
            q=q->next;
        }
        else
        {
            p->next=q;
            q=q->next;
            p=p->next;
        }
    }
    p->next=NULL;
    return head;

}
