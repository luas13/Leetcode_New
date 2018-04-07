class Solution {
public:
    void helper(int sr, int sc, int er, int ec, vector<vector<int>> &result, int v) 
    {
        while(sr<=er && sc<=ec)
        {
            for(int i=sc; i<=ec; i++)
                result[sr][i] = v++;
            sr++;

            for(int i=sr; i<=er; i++)
                result[i][ec] = v++;
            ec--;

            if (sr <= er)
            {
                for(int i=ec; i>=sc; i--)
                    result[er][i] = v++;
                er--;
            }

            if (sc <= ec)
            {
                for(int i=er; i>=sr; i--)
                    result[i][sc] = v++;
                sc++;
            }
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if (!n)
            return result;
        
        helper(0, 0, n-1, n-1, result, 1);
        return result;
    }
};