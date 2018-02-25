class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = nums.size();
        if (!l)
            return false;
        int s = 0;
        int e = l-1;
        
        while(s <= e)
        {
            while(s<e && nums[s] == nums[e])
                s++;
            
            int mid = s + (e-s)/2;
            if (nums[mid] == target)
                return true;
                
            else if (nums[s] <= nums[mid])
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
        return false;
    }
};