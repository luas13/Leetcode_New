class Solution {
public:
    // Beautiful Question
    // Neither DP nor backtracking helps here
    // Greedy approach works
    // At every step we try to stretch our reach
    // Once our iterator crosses our reach and its 
    // Check its editorial
    
    // Greedy, because at every point we are selecting a solution that seem
    // to be best possible solution at that time instead considering its 
    // past history or future.
    
    // O(N) solution with constant space
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        if (!l || l == 1)
            return 1;
        int reach = 0, i=0;
        
        for(; i<l && i<=reach; i++)
            reach = max(reach, i+nums[i]);
        
        return i == l;
    }
    
    /*
    // DP solution throwing TLE : 71/72 passed
    // Test case failing is an array of length 25003 and the elements being
    // {25000,24999,24998,24997,...3,2,1,1,0,0}
    // O(N*N) with O(N) space
    
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        if (!l || l == 1)
            return 1;
        vector<int> visited(l, 0);
        visited[0] = 1;
        for (int i=0; i<l; i++)
        {
            if (visited[i])
            {
                for(int j=1; j<=nums[i]; j++)
                {
                    visited[i+j] = 1;
                    if (i+j == l-1)
                        return 1;
                }
            }
        }
        return 0;
    }
    */
};