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
    ListNode* sortList(ListNode* head) {
        vector<int> s;

        if(head==nullptr)
        {
            return head;
        }

        ListNode* p=head;

        while(p!=nullptr)
        {
            s.push_back(p->val);
            p=p->next;
        }

        sort(s.begin(),s.end());

        p=head;

       for(int i=0;i<s.size();i++)
       {
           p->val=s[i];
           p=p->next;
       }

        return head;

    }
};