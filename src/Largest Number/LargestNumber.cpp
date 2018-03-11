int mycomparator(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a) ? 1: 0;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int l= nums.size();
        if (!l)
            return to_string(0);
        string result;
        
        sort(nums.begin(), nums.end(), mycomparator);
        for(int i=0; i<l; i++)
            result += to_string(nums[i]);
        
        if (result[0] == '0') 
            return to_string(0);
            
        return result;
    }
};