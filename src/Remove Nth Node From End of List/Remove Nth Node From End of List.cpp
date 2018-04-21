// Soln: 1, Short Soln
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return NULL;
        if (!head->next && n==1)
            return NULL;
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* ahead = head, *start = head, *prev=&dummy;
        
        for(int i=0; i<n-1; i++)
            ahead = ahead->next;
        while(ahead->next != NULL)
        {
            prev= start;
            start = start->next;
            ahead = ahead->next;
        }
        
        prev->next = start->next;
        start->next = NULL;
        delete(start);
        
        return dummy.next;
    }
};

// Soln: 2
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int i =0;
        
        if (n==0)
            return head;
            
        while(i<n && tmp)
        {
            tmp = tmp->next;
            i++;
        }
        
        if (i<n)
            return NULL;
            
        if (n == 1 && !tmp)
        {
            delete head;
            return NULL;
        }
            
        i= 0;
        ListNode* nthN = head;
        ListNode* prev = NULL;
        while(tmp && nthN)
        {
            prev = nthN;
            tmp = tmp->next;
            nthN = nthN->next;
        }
        
        ListNode* newhead;
        if (!prev)
        {
            newhead = head->next;
            delete head;
            return newhead;
        }
        
        prev->next = nthN->next;
        delete nthN;
        
        return head;
    }
};
