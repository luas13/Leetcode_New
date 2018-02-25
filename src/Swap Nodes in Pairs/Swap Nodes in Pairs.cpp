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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = head->next;
        ListNode* nN = newHead->next;
        newHead->next = head;
        head->next = nN;
        
        while(nN && nN->next)
        {
            ListNode* tmp = nN->next;
            nN->next = tmp->next;
            tmp->next = nN;
            head->next = tmp;
            head = nN;
            nN = nN->next;
        }
        
        return newHead;
    }
};