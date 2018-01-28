class Solution {
public:
    /*
    // DP solution O(N*N) ~ 13ms
    int wiggleMaxLength(vector<int>& nums) {
        int l = nums.size();
        if (l<=1)
            return l;
            
        // Incr[i] means maximum length of wiggle sequence 
        // ending with nums[i] & showing an increase at nums[i]
        // i.e nums[i] more than previous
        
        // Decr[i] means maximum length of wiggle sequence 
        // ending with nums[i] & showing a decrease at nums[i]
        // i.e nums[i] less than previous
        
        vector<int> Incr(l,0);
        vector<int> Decr(l,0);
        
        Incr[0] = 1;
        Decr[0] = 1;
        int maxlen = 1;
        
        for (int i =1; i<l; i++)
        {
            // Updating Incr[] and Decr[]
            for (int j=0; j<i; j++)
            {
                if (nums[i] > nums[j])
                    Incr[i] = max(Incr[i], Decr[j] + 1);
                
                else if (nums[i] < nums[j])
                    Decr[i] = max(Decr[i], Incr[j] + 1);
            }
            
            maxlen = max(maxlen, max(Incr[i], Decr[i]));
        }
        return maxlen;
    }
    */
    
    // DP Solution, O(N) ~ 0ms, O(N) space
    // See the editorial explanation if stuck 
    int wiggleMaxLength(vector<int>& nums) {
        int l = nums.size();
        if (l<=1)
            return l;
            
        // Incr[i] means maximum length of wiggle sequence 
        // ending with nums[i] & showing an increase at nums[i]
        // i.e nums[i] more than previous
        
        // Decr[i] means maximum length of wiggle sequence 
        // ending with nums[i] & showing a decrease at nums[i]
        // i.e nums[i] less than previous
        
        vector<int> Incr(l,0);
        vector<int> Decr(l,0);
        
        Incr[0] = 1;
        Decr[0] = 1;
        int maxlen = 1;
        
        for (int i =1; i<l; i++)
        {
            // Updating Incr[] and Decr[]
            if (nums[i] > nums[i-1])
            {
                Incr[i] = Decr[i-1] + 1;
                Decr[i] = Decr[i-1];
            }
                
            else if (nums[i] < nums[i-1])
            {
                Decr[i] = max(Decr[i], Incr[i-1] + 1);
                Incr[i] = Incr[i-1];
            }
            
            else
            {
                Incr[i] = Incr[i-1];
                Decr[i] = Decr[i-1];
            }
        }
        return max(Incr[l-1], Decr[l-1]);
    }
};


// DP soln O(n) time & O(1) space
// No need of array because we just need last element
// of incr or decr array

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int l = nums.size();
        
        if (!l)
            return 0;
        int inc= 1, dec= 1;
        for(int i=1; i<l; i++)
        {
            if (nums[i] > nums[i-1])
                inc= dec+1;
            else if (nums[i] < nums[i-1])
                dec= inc+1;
        }
        
        return max(inc, dec);
    }
};
