// Maintain an un-ordered map where key is array elements
// and value is a pair of <left, right>
// left: maximum consecutive sequence going from here to leftmost point
//          or left stretch
// right: maximum consecutive sequence going from here to rightmost point
//          or right stretch

// For every element check whether its immediate left value and 
// immediate right value is present in the map

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int l = nums.size();
        if (!l)
            return 0;
        unordered_map<int, pair<int,int> > mymap;
        // max count
        int maxc = 1;
        
        // max sequence starting point
        int maxs = INT_MIN;
        
        for (int i=0; i<l; i++)
        {
            // Imp Condition as numbers might be repeated so 
            // no use re-evaluating 
            if (mymap.find(nums[i]) == mymap.end())
            {
                // Check immediate left
                if ( mymap.find(nums[i] - 1) == mymap.end())
                {
                    // 1 element will have 1 lenght sequence 
                    // both towards it's left and right
                    mymap[nums[i]] = make_pair(1, 1);
                }
                else
                {
                    int v = mymap[nums[i] -1].first;
                    int left = v + 1;
                    // Update only left flag and obviously mark 
                    // it's right flag as 1 in this condn.
                    mymap[nums[i]] = make_pair(left, 1);
                    // Imp, Update it's leftmost/starting sequence's 
                    // right flag
                    mymap[nums[i] - v].second = left;

                    if (maxc < left)
                    {
                        maxc = left;
                        maxs = nums[i] - v;
                    }
                }

                // Check immediate right
                if ( mymap.find(nums[i] + 1) == mymap.end())
                {
                    // Left has already been updated
                    mymap[nums[i]].second = 1;
                }
                else
                {
                    // right stretch
                    int v = mymap[nums[i] +1].second;
                    // add left stretch and right stretch
                    int right = v + mymap[nums[i]].first;
                    
                    // update left stretch of rightmost element
                    mymap[nums[i] + v].first = right;
                    // update right stretch of leftmost element
                    mymap[nums[i] - (mymap[nums[i]].first - 1)].second = right;

                    if (maxc < right)
                    {
                        maxc = right;
                        maxs = nums[i] - (mymap[nums[i]].first - 1);
                    }
                }
            }
        }
        
        //cout<<"maxs is "<<maxs<<endl;
        //cout<<"maxc is "<<maxc;
        
        return maxc;
    }
};