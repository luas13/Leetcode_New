/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 

*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode() {
        this->isEnd= false;
        for(int i=0; i<26; i++)
            this->child[i]= NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* p= root;
        
        for(int i=0; i<s.size(); i++)
        {
            if(!p->child[s[i] - 'a'])
                p->child[s[i] - 'a']= new TrieNode();
            p=p->child[s[i] - 'a'];
        }
        
        p->isEnd= true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* p= root;
        for(int i=0; i<key.size(); i++)
        {
           if(!p->child[key[i] - 'a'])
            return false;
           p=p->child[key[i] - 'a'];
        }
        
        return p->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p= root;
        for(int i=0; i<prefix.size(); i++)
        {
           if(!p->child[prefix[i] - 'a'])
            return false;
           p=p->child[prefix[i] - 'a'];
        }
        
        return true; 
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
