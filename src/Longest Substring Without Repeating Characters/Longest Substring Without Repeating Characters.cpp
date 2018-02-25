// Without map, using an array

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size();
        if (!l)
            return 0;
        
        int maxl = INT_MIN;
        int len = 0, b=0;
        
        //unordered_map<int, int> mymap;
        int mymap[256];
        for(int i=0; i<256; i++)
            mymap[i] = INT_MIN;
        int i;
        for(i=0; i<l; i++)
        {
            if (mymap[int(s[i])] != INT_MIN)
            {
                len = i - b;
                if (len > maxl)
                    maxl = len;
                // imp
                b = max( (mymap[int(s[i])] + 1), b);
            }
            mymap[int(s[i])] = i;
        }
        if (maxl == INT_MIN)
            return i-b;
        else
            return max( maxl, i-b);
    }
};