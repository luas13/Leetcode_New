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
    // 1st Method: No dummy node and no recursion
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
            
        int flag = 0;
        ListNode* res = NULL;
        if (l1->val < l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else
        {
            res = l2;
            l2 = l2->next;
        }
        // ListNode** phead = &head;
        ListNode* head = res;
        
        while(l1 && l2)
        {
            if (l1->val < l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }
            
            res = res->next;
            flag = !flag;
        }
        if (l1)
            res->next = l1;
        if (l2)
            res->next = l2;
            
        return head;
    }
    
    // Recusrsion
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if (!l1)
    //         return l2;
    //     if (!l2)
    //         return l1;
        
    //     ListNode* res = NULL;    
    //     if (l1->val < l2->val)
    //     {
    //         res = l1;
    //         res->next = mergeTwoLists(l1->next, l2);
    //     }
    //     else
    //     {
    //         res = l2;
    //         res->next = mergeTwoLists(l1, l2->next)
    //     }
    //     return res;
    // }
};