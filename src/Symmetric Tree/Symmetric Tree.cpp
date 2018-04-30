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
    bool helper(TreeNode* a, TreeNode* b)
    {
        if (!a && !b)
            return true;
        if ( (!a && b) || (!b && a) )
            return false;
        if (a->val != b->val)
            return false;
        return (helper(a->left, b->right) && helper(a->right, b->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
};