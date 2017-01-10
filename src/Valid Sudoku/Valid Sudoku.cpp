class Solution {
public:
    bool isrowsafe(vector<vector<char>>& board, int r, int c, int num)
    {
        for(int i=0; i<9; i++)
        {
            if ((i != c) && board[r][i] == '0' + num)
                return false;
        }
        return true;
    }
    
    bool iscolsafe(vector<vector<char>>& board, int r, int c, int num)
    {
        for(int i=0; i<9; i++)
            if ((i != r) && board[i][c] == '0' + num)
                return false;
        return true;
    }
    
    bool is3x3safe(vector<vector<char>>& board, int r, int c, int num)
    {
        int inr = r - (r%3);
        int inc = c - (c%3);
        for(int i=inr; i<inr+3; i++)
            for(int j=inc; j<inc+3; j++)
                if (!(i == r && j == c) && board[i][j] == '0' + num)
                    return false;
        return true;
    }
    
    bool issafe(vector<vector<char>>& board, int r, int c, int num)
    {
        if (isrowsafe(board, r, c, num) && iscolsafe(board, r, c, num) && is3x3safe(board, r, c, num))
            return true;
        else
            return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int row= board.size();
        if (row != 9)
            return false;
        int col= board[0].size();
        if (col != 9)
            return false;
            
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if (board[i][j] != '.' && !issafe(board, i, j, board[i][j] - '0'))
                    return false;
            }
        }
        return true;
    }
};