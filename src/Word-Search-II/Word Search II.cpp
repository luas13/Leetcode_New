/*
****************Very Good Problem***************

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of 
data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you 
would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.


Solution:
1)Create a Trie of words to be searched.
2)For every character in the board, find it in trie and use DFS to search further

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

//private:
    TrieNode* root;
};

class Solution {
public:
    Trie mytrie;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int r= board.size();
        int c= board[0].size();
        
        unordered_set<string> ret;
        
        if( (r <= 0 ) || words.size() <= 0 )
            return vector<string>(ret.begin(), ret.end());
        
        vector<vector<bool>> visited( r, vector<bool>(c, false) );
        
        for(int i=0; i<words.size(); i++)
            mytrie.insert(words[i]);
            
        string curr;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                findWordsDFS(board, &(mytrie.root), visited, curr, i, j, ret);
            }
        }
        
        return vector<string>(ret.begin(), ret.end());
    }
    
    
    void findWordsDFS(vector<vector<char>> &board, TrieNode** root, vector<vector<bool>> &visited, string curr, int i, int j, unordered_set<string>& ret)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return;
            
        if(visited[i][j] || !(*root)->child[ board[i][j] - 'a' ] )
            return;
            
        TrieNode* nextNode= (*root)->child[ board[i][j] - 'a' ];
        
        curr.push_back(board[i][j]);
        
        if(nextNode->isEnd)
            ret.insert(curr);
            
        visited[i][j]= true;
        
        vector< pair<int,int> > direction{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        for(int k=0; k<4; k++)
            findWordsDFS(board, &nextNode, visited, curr, i + direction[k].first, j + direction[k].second, ret);
            
        visited[i][j]= false;
    }
};
