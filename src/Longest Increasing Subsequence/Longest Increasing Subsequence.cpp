class Solution {
public:
    // O(nlogn) Solution
    void BSreplace(vector<int>& dp, int s, int e, int v)
    {
        if (s > e)
            return;
        if (s == e)
        {
            dp[s] = v;
            return;
        }
        int mid = s + (e-s)/2;
        if (dp[mid-1] < v && v <= dp[mid])
        {
            dp[mid] = v;
            return;
        }
        if (dp[mid] < v)
            BSreplace(dp, mid+1, e, v);
        else
            BSreplace(dp, s, mid-1, v);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if (l == 0)
            return 0;
        //Active lists contain nums array values
        vector<int> dp;
        dp.push_back(nums[0]);
        
        int index = 0;
        
        for(int i=1; i<l; i++)
        {
            if (nums[i] > dp[index])
            {
                dp.push_back(nums[i]);
                index++;
            }
            else if (nums[i] < dp[index])
            {
                BSreplace(dp, 0, dp.size(), nums[i]);
            }
        }
        
        return dp.size();
    }
    /*
    // O(n^2) DP solution
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if (l == 0)
            return 0;
        vector<int> dp(l, 1);
        int maxv = 1;
        
        for (int i=1; i<l; i++)
        {
            for(int j=0; j<i; j++)
            {
                if (nums[j] < nums[i] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            maxv = max(maxv, dp[i]);
        }
        return maxv;
    }*/
};