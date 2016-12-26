//This question is a typical application of DP to solve the problem, if we see the total number of 
//requests, rather than listing all the problems, all likelihood is to use DP to solve, 
//the top priority is to find Out recursive.

//Similiar to knapsack problem
//dp[i][j] stands for max number of str we can pick from strs with limitation of i "0"s and j "1"s

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