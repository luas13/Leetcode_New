/*
The total unique paths at grid (r,c) is equal to the sum of total unique paths from grid to the right (r,c+1)
and the grid below (r+1,c).

The good part is we only used O(n) space and not O(mxn) space because we are only concerned about end total number of 
paths.So we used only a 1D array and manipulated it every time.

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!m || !n)
            return 0;
        
        vector<int> dp(n, 1);
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[j] = dp[j] + dp[j-1];
        
        return dp[n-1];
    }
};

OR,

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if( m==1 || n==1 ) 
            return 1;    
        
        vector<int> dp(n);
        for(int i=0; i<n; i++)
            dp[i]=1;
        
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-2; j>=0; j--)
            {
                dp[j]= dp[j] + dp[j+1];
            }
        }
        
        return dp[0];
        
    }
};

//2nd Solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!m || !n)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        vector< vector<int> > sol(m, vector<int>(n));
        for (int i=0; i<m; i++)
            sol[i][0] = 1;
        for (int i=0; i<n; i++)
            sol[0][i] = 1;
        for (int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                sol[i][j] = sol[i-1][j] + sol[i][j-1];
        return sol[m-1][n-1];
    }
};
