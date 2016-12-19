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
        return -1;
    }
    
    TreeNode *buildutil(vector<int> &postorder, vector<int> &inorder, int s, int e,int &mid)
    {
        if(s > e)
            return NULL;
    
        TreeNode* p=new TreeNode(postorder[mid--]);
    
        int l=search(inorder,p->val,s,e);
        
        p->right=buildutil(postorder,inorder,l+1,e,mid);
        p->left=buildutil(postorder,inorder,s,l-1,mid);
        
        return p;
    }

    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size()) {
            return NULL;
        }
        int l=postorder.size();
        int mid=l-1;
        return buildutil(postorder,inorder,0,l-1,mid);
    }
    
   
};
_____________________________________________________________________________________________________
OR,

class Solution {
public:
    int search(vector<int> &inorder, int key, int s, int e)
    {
        int i;
        for(i=0; i<=e; i++)
        {
            if(inorder[i] == key)
                return i;
        }
    }
    
    TreeNode *buildutil(vector<int> &inorder, vector<int> &postorder, int s, int e,int &posts, int poste)
    {
        //static int k=0;
    
        if(s > e || posts > poste)
            return NULL;
    
        TreeNode* p=new TreeNode(postorder[poste-posts]);
        posts++;
        
        int l=search(inorder,p->val,s,e);
    
        p->right=buildutil(inorder, postorder,l+1,e,posts,poste);
        p->left=buildutil(inorder, postorder,s,l-1,posts,poste);
        
        return p;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
       if (postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size()) {
            return NULL;
        }
        int l=postorder.size();
        int posts=0;
        return buildutil(inorder, postorder,0,l-1,posts,l-1); 
    }
};
