class Solution {
public:
    // int recsearch(vector<int>& nums, int s, int e, int t)
    // {
    //     if (s > e)
    //         return -1;
            
    //     int mid = s + (e-s)/2;
        
    //     if (nums[mid] == t)
    //         return mid;
            
    //     if (t < nums[mid])
    //     {
    //         if (nums[mid] >= nums[s] && nums[s] <= t)
    //             return recsearch(nums, s, mid-1, t);
    //         else
    //             return recsearch(nums, mid+1, e, t);
    //     }
    //     else
    //     {
    //         if (nums[mid] <= nums[e] && nums[e] >= t)
    //             return recsearch(nums, mid+1, e, t);
    //         else
    //             return recsearch(nums, s, mid-1, t);
    //     }
    // }

    int search(vector<int>& nums, int target) {
        int l = nums.size();
        if (!l)
            return -1;
        // return recsearch(nums, 0, l-1, target);
        
        int s = 0; 
        int e = l-1;
        int mid;
        
        while (s <= e)
        {
            mid = s + (e-s)/2;
            if (nums[mid] == target)
                return mid;
                
            if (nums[s] <= nums[mid])
            {
                if (nums[s] <= target && target < nums[mid])
                    e = mid-1;
                else
                    s = mid+1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[e])
                    s = mid+1;
                else
                    e = mid-1;
            }
        }
        return -1;
    }
};