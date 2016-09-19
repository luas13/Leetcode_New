/*
The total unique paths at grid (r,c) is equal to the sum of total unique paths from grid to the right (r,c+1)
and the grid below (r+1,c).

The good part is we only used O(n) space and not O(mxn) space because we are only concerned about end total number of 
paths.So we used only a 1D array and manipulated it every time.

*/

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
