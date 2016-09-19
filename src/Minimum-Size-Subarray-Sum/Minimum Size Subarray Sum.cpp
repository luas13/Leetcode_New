class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start= 0, end= 0;
        int l= nums.size();
        if(!l) 
          return 0;
          
        int curr_sum= 0;
        int min_length= INT_MAX;
        
        while(end < l)
        {
            while(curr_sum < s && end < l)
              curr_sum += nums[end++];
              
            while(curr_sum >= s && start < end)
            {
                if( (end - start ) < min_length )
                    min_length = end - start;
                
                curr_sum -= nums[start++];
            }
            
        }
        
        if(min_length != INT_MAX)
            return min_length;
        else
            return 0;
    }
};
