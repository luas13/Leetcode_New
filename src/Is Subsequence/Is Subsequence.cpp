/*
// C Solution ~22ms. 3lines
bool isSubsequence(char* s, char* t) {
    while (*t)
        s += *s == *t++;
    return (!*s);
}
*/

// Soln 2, c++ 5 lines, ~75ms
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length(), tl = t.length();
        int sidx = 0;
        for(int i=0; i<tl && sidx < sl; i++)
            if (t[i] == s[sidx]) sidx++;
        return sidx == sl;
    }
};
// ------------------------------------------------

// C++ solution ~ 86 ms
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        
        if (!ls && !lt)
            return 1;
        
        if (ls && !lt)
            return 0;
        
        int j=0;
        
        for(int i=0; i<ls; i++)
        {
            int flag =0;
            while(j<lt)
            {
                if (s[i] == t[j++])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
};
