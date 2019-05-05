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
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *slow = head, *fast = head;
        
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
            return NULL;
        
        ListNode* tmp= head;
        if (slow == fast)
        {
            while( tmp != slow)
            {
                tmp = tmp->next;
                slow = slow->next;
            }
            return slow;
        }
        return NULL;
        /*
        Let's say you also wanted to remove the loop
        In that case, create another pointer prev, such that
        
        ListNode* tmp= head;
        ListNode* prev;
        
        if (slow == fast)
        {
            while( tmp != slow)
            {
                prev = slow;
                tmp = tmp->next;
                slow = slow->next;
            }
            prev->next = NULL;
        }
        */
    }
};