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
 //维护两个链表一个存比target小的，其余的放另外一个里
class Solution {
public:
    ListNode* partition(ListNode* head, int x) { 
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;

        while(head) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        large->next = nullptr;
        small->next = largeHead->next;

        return smallHead->next;

    }
};