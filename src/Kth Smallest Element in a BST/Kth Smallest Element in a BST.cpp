/*
Go inorder and decrease k at each node. Stop the whole search as soon 
as k is zero, and then the k-th element is immediately returned all the 
way to the recursion top and to the original caller.

Try the left subtree first. If that made k zero, then its answer is 
the overall answer and we return it right away. Otherwise, decrease k 
for the current node, and if that made k zero, then we return the current 
node's value right away. Otherwise try the right subtree and return whatever 
comes back from there.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int &k)
    {
        if (root)
        {
            int v = helper(root->left, k);
            return !k ? v : !--k ? root->val : helper(root->right, k);
        }
        else
            return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};