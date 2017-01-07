class Solution {
public:
    // Vey simple: Based on Bucket sort
    // Intution: We can't sort but we need to achieve some kind
    // of sorted numbers so bucket sort comes into picture as
    // TC: O(N)
    int maximumGap(vector<int>& nums) {
        int l= nums.size();
        if(l < 2){
            return 0;
        }
        
        int minv= nums[0];
        int maxv= nums[0];
        
        for(int i=1; i<l; i++){
            if(nums[i] > maxv)
                maxv= nums[i];
            else if(nums[i] < minv)
                minv= nums[i]; 
        }
        
        if (maxv == minv)
            return 0;
        
        // ***Imp bucket size should be of type double and not int
        double bucket_size = double(maxv - minv)/double(l-1);
        vector<int> maxeach(l, INT_MIN);
        vector<int> mineach(l, INT_MAX);
        
        // Compute max & min among the numbers which falls on a index
        // We dont need to store all those numbers which belong to
        // a particular index. (For storing all numbers which falls at a particular
        // index we could have created a bucket, but here we just need min and 
        // max of each bucket)
        for(int i=0; i<l; i++)
        {
            int index = (nums[i] - minv)/bucket_size;
            maxeach[index] = max(maxeach[index], nums[i]);
            mineach[index] = min(mineach[index], nums[i]);
        }
        
        int maxgap = INT_MIN;
        // Maximum gap is min value of a particular index - prev max value
        // and not maxvalue of previous index
        // prev is important 
        
        int prev = maxeach[0];
        for(int i=1; i<l; i++)
        {
            if (mineach[i] == INT_MAX)
                continue;
            maxgap = max(maxgap, mineach[i] - prev);
            prev = maxeach[i];
        }
        
        return maxgap;
    }
};