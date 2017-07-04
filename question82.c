/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p,*q,*h,*r;
    h=NULL;
    if(!head||!head->next)return head;

    p=head;
    q=p->next;
    while(q||p)
    {
        if(q&&p&&q->val==p->val)
        {

                while(p&&p->val==q->val)
                    p=p->next;
                if(p)q=p->next;
                else q=NULL;
            if(h)
            {
                r->next=p;
            }
        }
        else
        {
            if(!h)
                h=p;
            r=p;
            if(p)
            p=p->next;
            if(q)
            q=q->next;
        }

    }
    return h;
}
