/*

For dp[i] ,there are two ways to reach ith step of stair.
1)Climb 1 step from (i-1)th level or 
2)climb 2 steps from(i-2)th level. 
Thus dp[i]= dp[i-1] + dp[i-2] with base cases dp[0]= 0 , dp[1]= 1, dp[2]= 2

*/

class Solution {
public:
    int climbStairs(int n) {
        vector< int > dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
 
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        
        return dp[n];
        
    }
};
