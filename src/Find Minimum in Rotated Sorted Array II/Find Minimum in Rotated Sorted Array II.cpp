class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return 0;
    
        if (l==1)
            return nums[0];
            
        int s = 0;
        int e = l-1;
    
        while(s<e)
        {
            while (s<e && nums[s] == nums[e])
                s++;
                
            int mid = s + (e-s)/2;
            
            if (nums[mid] > nums[e])
                s = mid+1;
            else if (nums[mid] < nums[e])
                e = mid;
            else
                e--;
        }
        return nums[s];
    }
};