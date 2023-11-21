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
    int getDecimalValue(ListNode* head) {
        stack<int> x_stack;
        int num=0;

        while(head!=nullptr)
        {
            x_stack.push(head->val);
            head=head->next;
        }

        int size=x_stack.size();

        for(int i=0;i<size;i++)
        {
            num+=x_stack.top()*pow(2,i);
            x_stack.pop();
        }

        return num;

    }
};