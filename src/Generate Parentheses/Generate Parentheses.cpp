class Solution {
public:
    void helper(vector<string>& res, int l, int open, int close, string str)
    {
        if (close == l)
        {
            res.push_back(str);
            return;
        }
        else
        {
            if (open > close)
                helper(res, l, open, close+1, str+")");
            if (open < l)
                helper(res, l, open+1, close, str+"(");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (!n)
            return res;
        string str= "";
        helper(res, n, 0, 0, str);
        return res;
    }
};