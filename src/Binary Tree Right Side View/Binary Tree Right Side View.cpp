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
    void printrightview(TreeNode* root, vector<int>& result, int level, int &maxlevel)
    {
        if (!root)
            return;
            
        if (maxlevel < level)
        {
            result.push_back(root->val);
            maxlevel = level;
        }
        
        printrightview(root->right, result, level+1, maxlevel);
        printrightview(root->left, result, level+1, maxlevel);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if (!root)
            return result;
        
        int maxlevel =-1;
        
        printrightview(root, result, 0, maxlevel);
        
        return result;
    }
};