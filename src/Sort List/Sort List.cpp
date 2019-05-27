// Soln: 1, Short and Clean
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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* head = &dummy;
        
        while(l1 && l2)
        {
            if (l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            }          
            else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = l1? l1 : l2;
        return dummy.next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        // fast = head->next
        ListNode* slow = head, *fast = head->next;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* headb = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(headb));
    }
};


// Too detailed
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
    void split(ListNode* head, ListNode*& a, ListNode*& b)
    {
        ListNode* fast= head->next;
        ListNode* slow = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        a = head;
        b = slow->next;
        slow->next = NULL;
    }
    
    ListNode* merge(ListNode* a, ListNode* b)
    {
        // Create a Dummy node 
        ListNode head(-1);
        
        // Imp step create a pointer out of dummy node
        ListNode* tmp = &head;
        
        while(a && b)
        {
            if (a->val < b->val)
            {
                tmp->next = a;
                a = a->next;
                
            }
            else
            {
                tmp->next = b;
                b = b->next;
            }
            
            tmp = tmp->next;
        }
        
        // if would also have served the purpose
        // as max diff in length of a & b is 1
        while (a)
        {
            tmp->next = a;
            a = a->next;
            tmp = tmp->next;
        }
        
        while (b)
        {
            tmp->next = b;
            b = b->next;
            tmp = tmp->next;
        }
        
        return head.next;
    }
    
    void listPrint(ListNode* head)
    {
        while(head)
        {
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<"NULL"<<endl;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
            
        ListNode* a=NULL;
        ListNode* b=NULL;
        split(head, a, b);
        
        // ListNode* l1 = sortList(a);
        // ListNode* l2 = sortList(b);
        
        // return merge(l1, l2);
        
        //OR in 1 line
        
        return merge(sortList(a), sortList(b));
    }
};
