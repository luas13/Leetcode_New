class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int l =coins.size();
        if (!l || !amount)
            return 0;
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=0; i<l; i++)
        {
            int c = coins[i];
            for(int j=c; j<=amount; j++)
                if (dp[j-c] != INT_MAX && dp[j-c] + 1 < dp[j])
                    dp[j] = dp[j-c] + 1;
        }
        
        if (dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }
};