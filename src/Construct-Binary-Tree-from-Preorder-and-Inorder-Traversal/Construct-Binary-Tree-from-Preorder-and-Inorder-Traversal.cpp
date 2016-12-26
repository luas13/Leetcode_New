/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    int search(vector<int> &inorder, int key, int s, int e)
    {
        int i;
        for(i=s; i<=e; i++)
        {
            if(inorder[i] == key)
                return i;
        }
        //return 0 otherwise compilation error
        return 0;
    }
    
    TreeNode *buildutil(vector<int> &preorder, vector<int> &inorder, int s, int e,int &mid)
    {
        //static int k=0;
        //no need of || preorder.size()==mid
        if(s > e || preorder.size()==mid)
            return NULL;
    
        TreeNode* p=new TreeNode(preorder[mid++]);
    
        int l=search(inorder,p->val,s,e);
    
        p->left=buildutil(preorder,inorder,s,l-1,mid);
        p->right=buildutil(preorder,inorder,l+1,e,mid);
    
        return p;
    }

    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) {
            return NULL;
        }
        int l=preorder.size();
        int mid=0;
        return buildutil(preorder,inorder,0,l-1,mid);
    }
    
   
};
