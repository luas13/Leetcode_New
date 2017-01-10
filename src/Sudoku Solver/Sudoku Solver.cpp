class Solution {
public:
    
    // Algorithm: Backtracking
    // ***IMP Step is where to start from
    
    // 1. Search for empty cell. If no empty cell return true. 
    // 2. Generate a no [1,9]
    // 3. Check if the no [1,9] is safe to insert.
    //  a. Check row wise
    //  b. Check column wise
    //  c. Check in a 3x3 window
    // 4. Insert the generated no and make a recursive call
    // 5. If the call returns true, return true
    // 6. If not remove the generated element from the just filled cell(Backtrack)
    // 7. After checking for all no [1,9] if no safe num found
    //    return false as soduko cannot be solved
    
    pair<int, int> findcell(vector<vector<char>>& board)
    {
        pair<int, int> p;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if (board[i][j] == '.')
                {
                    p.first = i;
                    p.second = j;
                    
                    return p;
                }
            }
        }
        p.first = -1;
        p.second = -1;
        return p;
    }
    
    bool isrowsafe(vector<vector<char>>& board, int r, int num)
    {
        for(int i=0; i<9; i++)
            if (board[r][i] == '0' + num)
                return false;
        return true;
    }
    
    bool iscolsafe(vector<vector<char>>& board, int c, int num)
    {
        for(int i=0; i<9; i++)
            if (board[i][c] == '0' + num)
                return false;
        return true;
    }
    
    bool is3x3safe(vector<vector<char>>& board, int r, int c, int num)
    {
        int inr = r - (r%3);
        int inc = c - (c%3);
        for(int i=inr; i<inr+3; i++)
            for(int j=inc; j<inc+3; j++)
                if (board[i][j] == '0' + num)
                    return false;
        return true;
    }
    
    bool issafe(vector<vector<char>>& board, int r, int c, int num)
    {
        if (isrowsafe(board, r, num) && iscolsafe(board, c, num) && is3x3safe(board, r, c, num))
            return true;
        else
            return false;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        pair<int, int> p = findcell(board);
        // No empty cell left, all are filled properly
        int r= p.first, c= p.second;
        if (r == -1 && c == -1)
            return true;
            
        for(int num=1; num<=9; num++)
        {
            if (issafe(board, r, c, num))
            {
                board[r][c] = '0' + num;
            
                if (solve(board))
                    return true;
                
                board[r][c] = '.';
            }
        }
        
        if (board[r][c] == '.')
            return false;
        // Extra statement as compile error in OJ
        else
            return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int row= board.size();
        if (row != 9)
            return;
        int col= board[0].size();
        if (col != 9)
            return;
            
        if (!solve(board))
            cout<<"Soduko cannot be solved!!!"<<endl;
    }
};