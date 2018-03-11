/*
You dont require inorder if you create a map of inorder array values 
& their index. You create nodes based on preorder array values only. 
All you need is to maintain start, end, *partition_index* & preorder_index
variable. Important is that you pass a preorder_index reference which 
starts with 0. U call either the left hand part of inorder array or 
right hand part based on partition_index's value analogy to mid in binary 
search.
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
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& mymap, int s, int e, int &preorder_index)
    {
        if (s > e)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preorder_index++]);
        int partition_index = mymap[root->val];
        root->left = helper(preorder, mymap, s, partition_index-1, preorder_index);
        root->right = helper(preorder, mymap, partition_index+1, e, preorder_index);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int il = inorder.size();
        int pl = preorder.size();
        
        if (!il && !pl || il != pl)
            return NULL;
        
        unordered_map<int, int> mymap;
        for(int i=0; i<il; i++)
            mymap[inorder[i]] = i;
        
        int preorder_index = 0;
        return helper(preorder, mymap, 0, il-1, preorder_index);
    }
};

------------------------------------------------------------------------------------------------
    
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
        if(s > e)
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
