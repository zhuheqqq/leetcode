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

    ListNode* reverseLinkNode(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* dummy = new ListNode(-1);
       dummy->next = head;

       ListNode* pre = dummy;
       for(int i = 0; i < left - 1; i++) {
        pre = pre->next;
       }

       ListNode* rightNode = pre;
       for(int i = 0; i <right - left + 1; i++) {
        rightNode = rightNode->next;
       }

       ListNode* leftNode = pre->next;
       ListNode* cur = rightNode->next;

       pre->next = nullptr;
       rightNode->next = nullptr;

       reverseLinkNode(leftNode);

       pre->next = rightNode;
       leftNode->next = cur;
       return dummy->next;
    }
};