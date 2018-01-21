Solution 1: Better than 38% soln

class Solution {
public:
    bool find(vector<vector<char>>& board, int r, int c, string word, int l)
    {
        if (l == word.size())
            return true;
        if (r<0 || c<0 || r>= board.size() || c>= board[0].size() || board[r][c] != word[l])
            return false;
        // boolean way of changing the value, here the visited cells
        board[r][c] ^= ~1;
        // if u return true after this condn i.e when it's true, remember u 
        // have left board[r][c] changed, if u want to avoid, take this result 
        // in a flag, do board[r][c] ^= ~1 & return that flag
        if (find(board, r, c-1, word, l+1) || find(board, r-1, c, word, l+1) || find(board, r, c+1, word, l+1) || find(board, r+1, c, word, l+1))
            return true;
        board[r][c] ^= ~1;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) { 
        for (int r=0 ; r<board.size(); r++)
            for (int c=0 ; c<board[0].size(); c++)
                if (find(board, r, c, word, 0) == true)
                    return true;
        return false;
    }
};

-----------------------------------------------------------------------------------------------------------------------
Solution 2: Better than 52% soln

class Solution {
public:
    bool isSafe(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        if (r < 0 || r >= board.size() || c <0 || c>= board[0].size() || visited[r][c] == true)
            return 0;
        else
            return 1;
    }
    
    bool find(vector<vector<char>>& board, int r, int c, string word, int l, vector<vector<bool>>& visited)
    {
        // if (r == board.size() && c== board[0].size())
        //     return false;
        //cout<<"l = "<< l<<endl;
        if (l == word.size()-1)
        {
            if (board[r][c] == word[l])
                return true;
            else
                return false;
        }
        
        if (isSafe(r, c, board, visited) && l<word.size())
        {
            if (board[r][c] == word[l])
            {
                visited[r][c] = true;
                
                bool flag1= false, flag2= false, flag3= false, flag4= false;
                //cout<<board[r][c]<<endl;
                //cout<<"l afetr board= "<<l<<endl;
                
                if (isSafe(r-1, c, board, visited) && board[r-1][c] == word[l+1])
                    flag1 = (find(board, r-1, c, word, l+1, visited));
                if (isSafe(r, c-1, board, visited) && board[r][c-1] == word[l+1])
                    flag2 =  (find(board, r, c-1, word, l+1, visited));
                if (isSafe(r, c+1, board, visited) && board[r][c+1] == word[l+1])
                    flag3 =  (find(board, r, c+1, word, l+1, visited));
                if (isSafe(r+1, c, board, visited) && board[r+1][c] == word[l+1])
                    flag4 = (find(board, r+1, c, word, l+1, visited));
                if (!(flag1 || flag2 || flag3 || flag4))
                    visited[r][c] = false;
                return (flag1 || flag2 || flag3 || flag4);
            }
            //cout<<"inter l= "<<l<<endl;
            //cout<<"inter r & c= "<<r<<" "<<c<<endl;
        }
        
        //cout<<"final l= "<< l<<endl;
        //cout<<"hey"<<endl;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = 0, c=0, l=0;
        
        int R = board.size();
        int C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (int r=0 ; r<board.size(); r++)
        {
            for (int c=0 ; c<board[0].size(); c++)
            {
                if (find(board, r, c, word, l, visited) == true)
                    return true;
            }
        }
        
        return false;
    }
};
-------------------------------------------------------------------------------------------------------------

Solution 3:
    
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
