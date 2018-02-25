class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int l = cost.size();
        
        vector<int> dp(l+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        int pprev = cost[0];
        int prev = cost[1];
        
        for(int i=1; i<l; i++)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        
        return min(dp[l-2], dp[l-1]);
    }
};