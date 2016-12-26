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