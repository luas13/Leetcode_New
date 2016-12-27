class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mymap={ {'I', 1},
                              {'V', 5},
                              {'X', 10},
                              {'L', 50},
                              {'C', 100},
                              {'D', 500},
                              {'M', 1000}
        };
        
        int val = mymap[s.back()];
        
        for (int i=s.length()-2; i>=0; i--)
        {
            if (mymap[s[i]] >= mymap[s[i+1]])
                val += mymap[s[i]];
            else
                val -= mymap[s[i]];
        }
        return val;
    }
};