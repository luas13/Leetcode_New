/*
Soln1: Space O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return 0;
        
        vector<int> dp(l, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<l; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        
        return dp[l-1];
    }
};
*/

// Soln2: Space O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return 0;
        
        int maxi = nums[0];
        int maxe = 0;
        
        for(int i=1; i<l; i++)
        {
            int tmp = maxi;
            maxi = max(maxi, maxe+nums[i]);
            maxe = max(maxe, tmp);
        }
        
        return max(maxi, maxe);
    }
};
