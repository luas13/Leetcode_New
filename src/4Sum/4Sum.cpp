// Similiar to 3Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l = nums.size();
        vector<vector<int>> result;
        
        if (!l)
            return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i < l; i++)
        {
            int target3 = target - nums[i];
            
            for(int j=i+1; j<l; j++)
            {
                int target2 = target3 - nums[j];
                
                int front = j+1;
                int back = l-1;
                
                while(front < back)
                {
                    int sum_two = nums[front] + nums[back];
                    
                    if (sum_two < target2)
                        front++;
                    else if (sum_two > target2)
                        back--;
                    else
                    {
                        vector<int> quad(4, 0);
                        // this give TLE
                        // quad.push_back(nums[i]);
                        // quad.push_back(nums[j]);
                        // quad.push_back(nums[front]);
                        // quad.push_back(nums[back]);
                        quad[0] =nums[i];
                        quad[1] =nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        
                        result.push_back(quad);
                        
                        while(front < back && nums[front] == quad[2])
                            front++;
                        while(back > front && nums[back] == quad[3])
                            back--;
                    }
                }
                while(j+1 < l && nums[j] == nums[j+1])
                    j++;
            }
            
            while(i+1 < l && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};