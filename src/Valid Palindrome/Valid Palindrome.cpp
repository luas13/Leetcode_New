class Solution {
public:
    bool isPalindrome(string s) {
        //char* str;
        vector<char> str;
        for(int i=0; i<s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                if (isalpha(s[i]))
                    str.push_back(tolower(s[i]));
                else
                    str.push_back(s[i]);
            }
        }
        int len = str.size();
        if (!len || len == 1)
            return true;
        int i,j;
        for (i=0, j=len-1; i<j; i++, j--)
        {
            if (str[i] != str[j])
                return false;
        }
        
        return true;
    }
};