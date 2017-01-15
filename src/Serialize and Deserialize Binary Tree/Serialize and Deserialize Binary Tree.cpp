/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeutil(TreeNode* root, string& s)
    {
        if (!root)
        {
            s += "#";
            return;
        }
        s += to_string(root->val) + ",";
        serializeutil(root->left, s);
        s += ",";
        serializeutil(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeutil(root, result);
        return result;
        
        // Or in 1 line
        // return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    int helper(string& data)
    {
        int pos = data.find(',');
        int v = stoi(data.substr(0, pos));
        data = data.substr(pos+1);
        return v;
    }

    TreeNode* deserializeutil(string& data)
    {
        if (data[0] == '#')
        {
            if (data.size() > 1) data = data.substr(2);
            return NULL;
        }
        TreeNode* root = new TreeNode(helper(data));
        root->left = deserializeutil(data);
        root->right = deserializeutil(data);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeutil(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));