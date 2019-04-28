// Draw diagram
// Only move pointer is incremeneted, rest is fixed
// in the sense that there's pointer are just changed

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        
        for(int i=0; i<m-1; i++)
            pre = pre->next;
        
        ListNode* curr = pre->next;
        for(int i=0; i<n-m; i++)
        {
            ListNode* move = curr->next;
            curr->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        
        return dummy.next;
    }
};
