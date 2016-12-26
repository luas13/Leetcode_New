class Solution {
public:
    int rob_linear(vector<int>& nums, int s, int e)
    {
        int l = nums.size();
        if (l == 0)
            return 0;
        int maxsi = nums[s];
        int maxse = 0;
        
        for(int i=s+1; i<e; i++)
        {
            int tmp = maxsi;
            maxsi = max(maxsi, maxse + nums[i]);
            maxse = max(maxse, tmp);
        }
        return max(maxsi, maxse);
    }
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (l == 0)
            return 0;
        if (l == 1)
            return nums[0];
        int m1 = rob_linear(nums, 0, l-1);
        int m2 = rob_linear(nums, 1, l);
        
        return max(m1,m2);
    }
};