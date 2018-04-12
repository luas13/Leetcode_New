class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        
        if(sl != tl)
            return false;
        
        vector<int> m1(256, -1);
        vector<int> m2(256, -1);
        
        for(int i=0; i<sl; i++)
        {
            if(m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = m2[t[i]] = i;
        }
        return true;
    }
};