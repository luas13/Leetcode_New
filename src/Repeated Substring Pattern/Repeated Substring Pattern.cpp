/*
Using LPS array of KMP

Imp. is return (lps[l-1] && l % (l-lps[l-1]) == 0);

Here we cheack whether lps[l-1] is not 0 &
l is divisible by l- lps[i], l-lps[i] is basically that string for which 
there is no proper prefix & proper suffix

*/

class Solution {
public:
    vector<int> computeLPS(string s)
    {
        int l = s.length();
        int i=1, j=0;
        vector<int> lps(l, 0);
        
        while(i<l)
        {
            if (s[i] == s[j])
            {
                lps[i] = j+1;
                i++;
                j++;
            }
            else
            {
                if (j)
                {
                    j = lps[j-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    
    bool repeatedSubstringPattern(string s) {
        int l = s.length();
        if (!l)
            return true;
        
        vector<int> lps = computeLPS(s);
        
        return (lps[l-1] && l % (l-lps[l-1]) == 0);
    }
};


//------------------------------------------------------------------------------
class Solution {
public:
    string leftshift(string str, int p)
    {
        string ret = str.substr(p);
        ret = ret + str.substr(0, p);
        return ret;
    }
    
    bool repeatedSubstringPattern(string str) {
        int len = str.length();
        if (len < 1)
            return false;
        int l = 0;
        for (int i=1; i<=len/2; i++)
        {
            if (len % i == 0)
            {
                string newstr = leftshift(str, i);
                if (!newstr.compare(str))
                    return true;
            }
        }
        return false;
    }
};
