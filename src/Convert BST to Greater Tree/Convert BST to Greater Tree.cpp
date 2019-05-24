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
    void helper(TreeNode* root, int &toadd)
    {
        if (!root)
            return;
        
        helper(root->right, toadd);
        
        root->val += toadd;
        toadd = root->val;
        
        helper(root->left, toadd);
    }
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        int toadd = 0;
        
        helper(root, toadd);
        return root;
    }
};