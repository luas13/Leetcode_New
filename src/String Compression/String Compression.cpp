/*
i: new index after a repeated character is processed, 
eg. aaaabb, after a is processed i is updated to 4 from 0

t: index upto which the compressed string go
j: to iterate the given string
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int l = chars.size();
        if (!l)
            return 0;
        
        int i=0, t=0;
        for(int j=0; j<l; j++)
        {
            if (j+1 == l || chars[j] != chars[j+1])
            {
                chars[t++] = chars[j];
                if (j>i)
                {
                    string s = to_string(j-i+1);
                    for(char c: s) chars[t++] = c;
                }
                i = j+1;
            }
        }
        return t;
    }
};
