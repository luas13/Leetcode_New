class Solution {
public:
    // Used the same function used to calculate maximum rectangular area in a histogram
    // This question is just calculating the maximum rectangular area for each row of 
    // given matrix and finally returning the max area of all rows
    
    int maxrect_hist(vector<int>& row)
    {
        int l= row.size();
        if (l < 2)
            return l == 0 ? 0: row[0];
        stack<int> s;
        int i=0;
        int max_area = INT_MIN;
        
        while (i < l)
        {
            if (s.empty() || row[s.top()] <= row[i])
                s.push(i++);
                
            else
            {
                int topi = s.top();
                s.pop();
                
                max_area = max(max_area, row[topi] * (s.empty() ? i : i-1 - s.top()));
            }
        }
        while (!s.empty())
        {
            int topi = s.top();
            s.pop();
                
            max_area = max(max_area, row[topi] * (s.empty() ? l : l-1 - s.top()));
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (!r)
            return 0;
        int c = matrix[0].size();
        if (r == 1 && c == 1)
            return matrix[0][0] - '0';
        
        // Given matrix contains char matrix, we need integer matrix
        // To optimise space we just use 2rows with no of columns same as given matrix 
        // and not r rows of given matrix
        
        vector<vector<int>> introwpair(2,vector<int>(c,0));
        for (int i =0; i<c; i++)
            introwpair[0][i] = matrix[0][i] - '0';
        
        int maxrect_area = maxrect_hist(introwpair[0]);
        
        for (int i=1; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (matrix[i][j] == '1')
                    introwpair[i%2][j] = introwpair[1-i%2][j] + 1;
                else 
                    introwpair[i%2][j] = 0;
            }
            maxrect_area = max(maxrect_area, maxrect_hist(introwpair[i%2]));
        }
        
        return maxrect_area;
    }
};