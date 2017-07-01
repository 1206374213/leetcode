
 // Definition for singly-linked list.
 // struct ListNode {
//      int val;
 //     struct ListNode *next;
 // };
 struct ListNode* ReverseList1(struct ListNode *l);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 //   return ReverseList1(l1);
    struct ListNode *r1,*r2,*r3,*head,*left;
   // r1=ReverseList1(l1);
  //  r2=ReverseList1(l2);
  r1=l1;
  r2=l2;
    int flag=0;
    head=r1;
    while(r1!=NULL&&r2!=NULL)
    {
        if(flag==1)
        {
            flag=0;
            r1->val++;
        }
        if((r1->val+r2->val)>=10)
        {
            flag=1;
         
        }
      //  r3=(struct ListNode*)malloc(sizeof (struct ListNode));
        r1->val=(r1->val+r2->val)%10;
      // r3=r3->next;
        r3=r1;
        r1=r1->next;
        r2=r2->next;
    }
    left=(r1==NULL?r2:r1);
    r1=r3;
    while(left!=NULL){
        if(flag==1)
        left->val++;
        flag=0;
        if(left->val>=10)
        {
              flag=1;
          
        }
        r3=(struct ListNode*)malloc(sizeof (struct ListNode));
        r3->val=(left->val)%10;
        r3->next=NULL;
        r1->next=r3;
        r1=r1->next;
        left=left->next;
    }
    if(flag==1)
    
    {
        r3=(struct ListNode*)malloc(sizeof (struct ListNode));
        r3->val=1;
        r3->next=NULL;
        r1->next=r3;
        r1=r1->next;
    }
    return head;
    
}

struct ListNode* ReverseList1(struct ListNode *l)
{
    struct ListNode *p,*r,*head;
    p=l;
    r=l->next;
    head=l;
    while(r!=NULL)
    {
        p->next=r->next;
        r->next=head;
        head=r;
        r=p->next;
    }
    
    return head;
}