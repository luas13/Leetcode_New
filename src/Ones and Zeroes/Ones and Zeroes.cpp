//This question is a typical application of DP to solve the problem, if we see the total number of 
//requests, rather than listing all the problems, all likelihood is to use DP to solve, 
//the top priority is to find Out recursive.

/*
Knapsack problem

***Top Down Approach***
int knapsack(int val[], int wt[], int n, int W)
{
   int dp[n+1][W+1];
   memset(dp, 0, sizeof dp);
   for (int i = 1; i <= n; i++)
   {
       for (w = 1; w <= W; w++)
       {
           dp[i][w] = dp[i-1][w];  //don't include the item
           if (wt[i-1] <= w)
                 dp[i][w] = max(dp[i][w], 
                           val[i-1] + dp[i-1][w-wt[i-1]]);  
       }
   }
   return dp[n][W];
}


***Bottom Up Approach***
int knapsack(int val[], int wt[], int n, int W)
{
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i < n; i++) 
        for(int j=W; j>=wt[i]; j--)
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
    return dp[W];
}

This problem is similiar to knapsack problem Bottom Up Approach
dp[i][j] stands for max number of str we can pick from strs with limitation of i "0"s and j "1"s
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        for(int i=0; i<strs.size(); i++)
        {
            int zeros = 0;
            int ones = 0;
            for(int j=0; j<strs[i].length(); j++)
            {
                if (strs[i][j] == '0')
                    zeros++;
                else
                    ones++;
            }
            
            for (int j=m; j>=zeros; j--)
            {
                for(int k=n; k>=ones; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
