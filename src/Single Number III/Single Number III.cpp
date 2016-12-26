class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0){
            ans.push_back(0);
             return ans;
        }
           
        int xor_all = nums[0];
        int a= 0;
        int b= 0;
        
        for (int i= 1; i<nums.size(); i++)
        {
            xor_all ^= nums[i]; 
        }
        
        int right_set_bit = xor_all & ~(xor_all - 1);
        for (int i= 0; i < nums.size(); i++)
        {
            if (right_set_bit & nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        
        ans.push_back(a);
        ans.push_back(b);
                
        return ans;
    }
};