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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        vector<int> vec;
        int j=1;
        ListNode *p=head;

        while(p!=nullptr)
        {
            if(p->val==0)
            {
                vec.push_back(sum);
                sum=0;
            }else{
                sum+=p->val;
            }
            p=p->next;
        }
        p=head;

        for(j=1;j<vec.size()-1;j++)
        {
            p->val=vec[j];
            p=p->next;
        }
        p->val=vec[j];
        p->next=nullptr;

        return head;
        
    }
};