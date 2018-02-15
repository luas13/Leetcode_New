/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 

*/
// 1st Method: private variables in TrieNode. Pure OOP in C++

class TrieNode{
private:
    bool isEnd;
    TrieNode* child[26];
    
public:
    TrieNode()
    {
        for(int i=0; i<26; i++)
            this->child[i] = NULL;
        this->isEnd = false;
    }
    
    bool getEnd()
    {
        return isEnd;
    }
    
    void setEnd(bool val)
    {
        this->isEnd = val;
    }
    
    TrieNode* getChild(int index)
    {
        return child[index];
    }
    
    void setChild(int index)
    {
        this->child[index] = new TrieNode();
    }
    
    void setChild2(int index, TrieNode* tchild)
    {
        this->child[index] = tchild;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int l = word.length();
        TrieNode* p = root;
        if (!l)
            return;
        
        for(int i=0; i<l; i++)
        {
            int index = word[i] - 'a';
            // if (!p->getChild(index))
            //     p->setChild(index);
            // Or,
            if (!p->getChild(index))
                p->setChild2(index, new TrieNode());
            p = p->getChild(index);
        }
        p->setEnd(true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int l = word.length();
        if(!l)
            return true;
        TrieNode* p = root;
        
        for (int i=0; i<l; i++)
        {
            int index = word[i] - 'a';
            if (!p->getChild(index))
                return false;
            p = p->getChild(index);
        }
        return p->getEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int l = prefix.length();
        if(!l)
            return true;
        TrieNode* p = root;
        for (int i=0; i<l; i++)
        {
            int index = prefix[i] - 'a';
            if (!p->getChild(index))
                return false;
            p = p->getChild(index);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

--------------------------------------------------------------------------------------------------------------------
// Public variables in TrieNode
    
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
