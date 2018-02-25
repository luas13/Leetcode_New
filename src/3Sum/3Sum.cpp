class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        vector<int> triplet(3);
        
        sort(nums.begin(), nums.end());
        int l= nums.size();
        
        for(int i=0; i<l; i++)
        {
            int j=i+1;
            int k = l-1;
            
            while(j < k)
            {
                int sum_two = nums[i] + nums[j];
                if (sum_two + nums[k] < 0)
                    j++;
                else if (sum_two + nums[k] > 0)
                    k--;
                else
                {
                    triplet[0] = nums[i];
                    triplet[1] = nums[j];
                    triplet[2] = nums[k];
                    
                    triplets.push_back(triplet);
                    
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while(j < k && nums[j] == triplet[1])
                        j++;
                    
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while(j < k && nums[k] == triplet[2])
                        k--;
                }
            }
            
            // Processing duplicates of Number 1
            while(i+1 < l && nums[i+1] == nums[i])
                i++;
        }
        return triplets;
    }
};