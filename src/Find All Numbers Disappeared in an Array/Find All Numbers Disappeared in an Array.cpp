class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.size() == 0)
            return (vector<int>{});
        
        vector<int> result;
        
        for(int i= 0; i<nums.size(); i++){
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        
        for(int i=0; i<nums.size(); i++)
            if (nums[i] > 0)
                result.push_back(i+1);
            
        return result;
    }
};