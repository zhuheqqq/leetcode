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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p;
        int flag=-101;
        if(head==nullptr)
        {
            return head;
        }
        while(head&&((head->next&&head->val==head->next->val)||head->val==flag))
        {
            flag=head->val;
            cout<<flag<<endl;
            head=head->next;
        }
        
        p=head;

        while(p&&p->next&&p->next->next)
        {
            if(p->next->val==p->next->next->val)
            {
                flag=p->next->val;
                while(p->next&&p->next->val==flag)
                {
                    p->next=p->next->next;
                }
            }else{
                p=p->next;
            }
        }
        return head;
    }
};