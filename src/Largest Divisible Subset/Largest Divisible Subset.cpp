#define rep(i,n) for(int i=0; i<n; i++)
#define repv(i,n,v) for(int i=v; i<n; i++)
#define repb(i,n) for(int i=n-1; i>=0; i--)


// Similiar to LIS DP solution
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int l = nums.size();
        vector<int> result(0);
        vector<int> parent(l, 0);
        vector<int> len(l,0);
        if (!l)
            return result;
            
        // Sort to use DP
        // len[i] is length of answer subset starting from i 
        // parent for marking the parents and retrieve the result
        // startindex of resultant subset
        
        sort(nums.begin(), nums.end());
        int maxlen = 0;
        int startindex = 0;
        
        repb(i,l)
        {
            repv(j,l,i)
            {
                if (nums[j] % nums[i] == 0 && len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    parent[i] = j;
                    
                    if (len[i] > maxlen)
                    {
                        maxlen = len[i];
                        startindex = i;
                    }
                }
            }
        }
        
        rep(i,maxlen)
        {
            result.push_back(nums[startindex]);
            startindex = parent[startindex];
        }
        return result;
    }
};