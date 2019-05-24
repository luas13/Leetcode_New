/*
Assumption in problem:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

// Passing LONG_MIN & LONG_MAX for starting min & max values
class Solution {
public:
    bool helper(TreeNode* root, long minv, long maxv)
    {
        if (!root)
            return true;
        // think of test case: [2147483647]
        // you will need to pass LONG_MIN & LONG_MAX
        if (root->val <= minv || root->val >= maxv)
            return false;
        return helper(root->left, minv, root->val) && helper(root->right, root->val, maxv);
    }
    
    bool isValidBST(TreeNode* root) {
        long minv = LONG_MIN;
        long maxv = LONG_MAX;
        return helper(root, minv, maxv);
    }
};

// If LONG_MIN & LONG_MAX are not allowed
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* minN, TreeNode* maxN)
    {
        if (!root)
            return true;
        // think of test case: [2147483647]
        // it's good to pass TreeNode* minN & maxN
        if ( (minN && root->val <= minN->val) || (maxN && root->val >= maxN->val) )
            return false;
        return helper(root->left, minN, root) && helper(root->right, root, maxN);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};


// Using just the previous value
class Solution {
public:
    bool helper(TreeNode* root, long& prev)
    {
        if (!root)
            return true;
        if (helper(root->left, prev)){
            if (root->val > prev)
            {
                prev = root->val;
                return helper(root->right, prev);
            }
            else
                return false;
        }
        else
            return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return helper(root, prev);
    }
};