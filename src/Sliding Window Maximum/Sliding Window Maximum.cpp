class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> result;
        int n= nums.size();
        
        
        if(n==0 || k==0){
            //result.push_back(NULL);
            return result;
        }
        
            
        deque<int> dq(k);
        int i;
        
        for(i=0; i<k; i++){
            
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        for(; i<n; i++){
            result.push_back(nums[dq.front()]);
            
            while(!dq.empty() && dq.front() <= (i-k) )
                dq.pop_front();
            
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
                
            dq.push_back(i);
        }
        
        result.push_back( nums[dq.front()] );
        
        return result;
    }
};