class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (l == 0)
            return 0;
        int maxsi = nums[0];
        int maxse = 0;
        
        for(int i=1; i<l; i++)
        {
            int tmp = maxsi;
            maxsi = max(maxsi, maxse + nums[i]);
            maxse = max(maxse, tmp);
        }
        return max(maxsi, maxse);
    }
};