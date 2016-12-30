// Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        // Greedy Solution as used in Jump Game problem
        
        int l= nums.size();
        if (!l || l==1)
            return 0;
        
        vector<int> minjumps(l, INT_MAX);
        minjumps[0] = 0;
        int reach =0;
        int i=0;
        for (; i<l && i<=reach; i++)
        {
            int prevreach = reach;
            if (reach < i+nums[i])
            {
                reach = i+nums[i];
                while(prevreach+1 < l && prevreach+1 <= reach)
                {
                    minjumps[prevreach+1] = min(minjumps[prevreach+1], minjumps[i] + 1);
                    if (prevreach+1 == l-1)
                        return minjumps[prevreach+1];
                    prevreach++;
                }
            }
        }
        return minjumps[l-1];
        
        /*
        // DP solution throws TLE 
        // 90/91 passed. failed: array of length 25002 and the elements being
        // {25000,24999,24998,24997,...3,2,1,1,0} 
        
        int l= nums.size();
        if (!l || l==1)
            return 0;
        cout<<l;
        vector<int> minjumps(l, INT_MAX);
        minjumps[0] = 0;
        for (int i=0; i<l; i++)
        {
            for (int j=i+1; j<=i+nums[i] && j<l; j++)
            {
                minjumps[j] = min(minjumps[j], minjumps[i] + 1);
                if (j == l-1)
                    return minjumps[j];
            }
        }
        return minjumps[l-1];
        */
    }
};