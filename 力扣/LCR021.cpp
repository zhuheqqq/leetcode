/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode*dummy=new ListNode();
       dummy->next=head;
       ListNode *p=dummy;
       int i,j;

       for(i=0;p->next!=nullptr;i++)
       {
           p=p->next;
       }
       p=dummy;

       for(j=0;j<i-n;j++)
       {
           p=p->next;
           
       }
       
       p->next=p->next->next;

       return dummy->next;

    }
};