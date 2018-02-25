class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return 0;
        int s = 0;
        int e = l-1;
        int mid;
        
        while(nums[s] > nums[e])
        {
            mid = s + (e-s)/2;
            if (nums[mid] < nums[s])
                e = mid;
            else
                s = mid+1;
        }
        
        return nums[s];
    }
};