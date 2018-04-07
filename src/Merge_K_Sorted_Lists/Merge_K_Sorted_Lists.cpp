// Soln 1: Using Priority Queue
// O(nlogk) Space O(k)
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
    struct mycompare{
        bool operator() (ListNode* p1, ListNode* p2)
        {
            return p1->val > p2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = lists.size();
        if (!l)
            return NULL;
        
        if (l==1)
            return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, mycompare> pq;
        
        for(int i=0; i<l; i++)
            if (lists[i])
                pq.push(lists[i]);
        
        // head(0) is a dummy node
        // 2 ways either to use a dummy node
        // or initialise the LL using a value
        ListNode *result, head(0);
        result = &head;
        
        while(!pq.empty())
        {
            ListNode* top = pq.top();
            pq.pop();
            
            if (top->next)
                pq.push(top->next);
            
            top->next = NULL;
            
            result->next = top;
            result = result->next;
        }
        return head.next;
    }
};



//-----------------------------------------------------------
// Soln 2 Divide & Conquer O(nlogk) Space O(1)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = lists.size();
        if (!l)
            return NULL;
        if (l==1)
            return lists[0];
        
        return doMerge(lists, 0, l-1);
    }
    
    ListNode* doMerge(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l+1 == r)
            return merge2Lists(lists[l], lists[r]);
        
        int mid = l + (r-l)/2;
        ListNode* l1 = doMerge(lists, l, mid);
        ListNode* l2 = doMerge(lists, mid+1, r);
        
        return merge2Lists(l1, l2);
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        tail->next = NULL;
        
        while(1)
        {
            if (!l1)
            {
                tail->next = l2;
                break;
            }
            
            if (!l2)
            {
                tail->next = l1;
                break;
            }
            
            // we could have used extra movenode() to physically remove
            // node from source & add to destination
            // check this link for it https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
            // i've played just on pointers
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            
            tail = tail->next;
        }
        return dummy.next;
    }
};