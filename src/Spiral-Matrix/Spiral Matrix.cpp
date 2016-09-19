vector<int> spiralPrint(vector<vector<int>> &matrix ,int sr, int er, int sc, int ec, vector<int> result)
{
    //vector<int> result;
    
    while(sr <= er && sc <= ec)
    {
        for(int i= sc; i <= ec; i++)
            result.push_back(matrix[sr][i]);
        sr++;
        
        for(int i= sr; i <= er; i++)
            result.push_back(matrix[i][ec]);
        ec--;
        
        if(sr <= er)
        {
            for(int i= ec; i >= sc; i--)
               result.push_back(matrix[er][i]);
            er--;
        }
        
        if(sc <= ec)
        {
            for(int i= er; i >= sr; i--)
               result.push_back(matrix[i][sc]);
            sc++;
        }
    }
    
    return result;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int row= matrix.size();
        if(row == 0)
          return result;;
        int col= matrix[0].size();
        return spiralPrint(matrix, 0, row-1, 0, col-1, result);
    }
};

