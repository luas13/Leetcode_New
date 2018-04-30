class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        if (!l)
            return true;
        stack<int> mys;
        for(int i=0; i<l; i++)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                mys.push(s[i]);
            else
            {
                if (s[i] == '}')
                {
                    if (mys.empty() || mys.top() != '{')
                        return false;
                    else
                        mys.pop();
                }
                if (s[i] == ')')
                {
                    if (mys.empty() || mys.top() != '(')
                        return false;
                    else
                        mys.pop();
                }
                    
                if (s[i] == ']')
                {
                    if (mys.empty() || mys.top() != '[')
                        return false;
                    else
                        mys.pop();
                }
            }
        }
        return mys.empty();   
    }
};