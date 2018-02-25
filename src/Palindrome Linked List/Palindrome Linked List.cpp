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
    bool ispalin(ListNode*& a, ListNode* b)
    {
        if (!b)
            return true;
        bool isp = ispalin(a, b->next);
        if (!isp)
            return false;
    
        bool isp1 = a->val == b->val;
        a = a->next;
        
        return isp1;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* b = head->next;
        return ispalin(head, b);
    }
};