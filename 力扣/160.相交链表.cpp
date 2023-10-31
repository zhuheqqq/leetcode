/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* lA=headA;
        ListNode* lB=headB;
        int lena=0,lenb=0;
        while(lA!=NULL)
        {
            lena++;
            lA=lA->next;
        }
        lA=headA;
        while(lB!=NULL)
        {
            lenb++;
            lB=lB->next;
        }
        lB=headB;

        if(lenb>lena)
        {
            swap(lena,lenb);
            swap(lA,lB);
        }

        int gap=lena-lenb;
        while(gap--)
        {
            lA=lA->next;
        }

        while(lA!=NULL)
        {
            if(lA==lB)
            {
                return lA;
            }
            lA=lA->next;
            lB=lB->next;
        }

        return NULL;
        
    }
};
// @lc code=end

