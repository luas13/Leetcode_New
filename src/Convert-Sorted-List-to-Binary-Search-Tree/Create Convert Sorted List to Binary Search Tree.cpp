/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode* convert(struct ListNode *&head,int s,int e)
{
    if(s > e)
        return NULL;
    int mid=s + (e - s)/2;
    
    struct TreeNode* lchild=convert(head,s,mid-1);
    
    struct TreeNode* par=new TreeNode(head->val);
    par->left=lchild;
    
    head=head->next;
    
    par->right=convert(head,mid+1,e);
    
    return (par);
}

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int s=0;
        int e=0;
        struct ListNode* tmp=head;
        while(tmp)
        {
            e++;
            tmp=tmp->next;
        }
        return ( convert(head,s,e-1) );
    }
};
