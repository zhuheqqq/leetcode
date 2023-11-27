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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p=head;
        ListNode *cur=head;
        int i=1,j=1;//用来统计链表节点个数从1开始

        while(p!=nullptr)
        {
            p=p->next;
            i++;
            if(i==k)
            {
                cur=p;
            }
        }
        p=head;

        while(j<i-k)
        {
            p=p->next;
            j++;
        }

        int t=p->val;
        p->val=cur->val;
        cur->val=t;

        return head;
        
    }
};