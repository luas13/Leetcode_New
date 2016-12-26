//Similiar to coin change problem
class Solution {
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        
        int sqrt_n = sqrt(n);
        if (sqrt_n * sqrt_n == n)
            return 1;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<=sqrt_n; i++)
        {
            int val = i*i;
            for (int j=val; j<=n; j++)
            {
                if (dp[j-val] != INT_MAX && dp[j] > dp[j-val] + 1)
                    dp[j] = dp[j-val] + 1;
            }
        }
        if (dp[n] == INT_MAX)
            return n;
        else
            return dp[n];
    }
};