/*
The diameter of a tree T is the largest of the following quantities:

* the diameter of T’s left subtree
* the diameter of T’s right subtree
* the longest path between leaves that goes through the root of 
T (this can be computed from the heights of the subtrees of T)

If the diameter means number of nodes on the longest path between two end nodes
return the answer as it is but if it means path length then return result - 1
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
    int helper(TreeNode* root, int &height)
    {
        int lh = 0, rh = 0;
        int ld = 0, rd = 0;
        
        if (!root)
        {
            height = 0;
            return 0;
        }
        
        ld = helper(root->left, lh);
        rd = helper(root->right, rh);
        
        height = max(lh, rh) + 1;
        
        return max( lh + rh + 1, max(ld, rd) );
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int height = 0;
        
        return helper(root, height)-1;
    }
};