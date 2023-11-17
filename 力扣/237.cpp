/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //思路是节点值往前覆盖
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p=node;
        ListNode* cur;
        while(node)
        {
            node=node->next;
            if(node==NULL)
            {
                cur->next=NULL;
                return;
            }
            p->val=node->val;
            cur=p;
            p=p->next;
        }
        return;
        
    }
};