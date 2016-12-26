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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        else{
            TreeNode* lt= invertTree(root->left);
            TreeNode* rt= invertTree(root->right);
            
            TreeNode* tmp= lt;
            root->left= rt;
            root->right= tmp;
            
            return root;
        }
        
    }
};