/*
For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + Max path through Right Child (no 
ancestors of root are there in max sum path )

The idea is to keep trace of four paths and pick up the max one in the end. 
An important thing to note is, root of every subtree need to return maximum 
path sum such that at most one child of root is involved. This is needed for 
parent function call. In below code, this sum is stored in ‘max_single’ and 
returned by the recursive function.

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
    // make it a practise to declare variables here
    int res;
public:
    int helper(TreeNode* root, int &res)
    {
        //Base Case 
        if (root == NULL) 
            return 0; 

        // l and r store maximum path sum going through left and 
        // right child of root respectively 
        int l = helper(root->left,res); 
        int r = helper(root->right,res); 

        // Max path for parent call of root. This path must 
        // include at-most one child of root 
        int max_single = max(max(l, r) + root->val, root->val); 

        // Max Top represents the sum when the Node under 
        // consideration is the root of the maxsum path and no 
        // ancestors of root are there in max sum path 
        int max_top = max(max_single, l + r + root->val); 

        res = max(res, max_top); // Store the Maximum Result. 

        // imp bcz max_single can only help in getting max_sum
        // either root+left or root+right path going upward
        // and getting larger sum by adding this root node
        return max_single; 
    }

    int maxPathSum(TreeNode* root) {
        // very important because there might only be -ve values for
        // all nodes
        res = INT_MIN;
        helper(root, res);
        return res;
    }
};