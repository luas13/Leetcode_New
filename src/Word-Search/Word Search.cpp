/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Solution:
Simple Backtracking with a 2D mask/visited array

*/
class Solution {
public:
    bool exist_check(vector<vector<char>>& board, string word, vector<vector<bool>>& m, int i, int j, int idx)
    {
        int r= i;
        int c= j;
        
        if(board[r][c] == word[idx] && !m[r][c])
        {
            if(idx+1 == word.size() )
                return true;
            
            idx++;
            m[r][c]= true;
            
            if( ( c < (board[0].size() - 1) && exist_check(board, word, m, r, c+1, idx) ) || 
                ( r < (board.size() - 1)    && exist_check(board, word, m, r+1, c, idx) ) ||
                ( c > 0                     && exist_check(board, word, m, r, c-1, idx) ) ||
                ( r > 0                     && exist_check(board, word, m, r-1, c, idx) ) )
            {
                return true;
            }
            
            m[r][c]= false;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r= board.size();
        int c= board[0].size();
        
        if( (r <= 0 ) || word.size() <= 0 )
            return false;
            
        //using a mask to mark which character has been selected.
        vector<vector<bool> > mask(r, vector<bool>(c, false) ); 
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> m= mask;                       //evertime m is updated back to default
                    if( exist_check(board, word, m, i, j, 0) )
                        return true;
                }
            }
        }
        
        return false;
        
    }
};
