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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*dummy=new ListNode();
        dummy->next=head;
        ListNode *p=dummy;
        int size=0;

        while(p->next!=nullptr)
        {
            size++;
            p=p->next;
        }

        p=dummy;
        for(int i=0;i<size/2;i++)
        {
            p=p->next;
        }
        p->next=p->next->next;

        return dummy->next;
        
    }
};