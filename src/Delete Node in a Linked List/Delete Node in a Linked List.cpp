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
    void deleteNode(ListNode* node) {
        if (node->next)
        {
            ListNode* nN = node->next;
            node->val = nN->val;
            node->next = nN->next;
            delete nN;
        }
    }
};