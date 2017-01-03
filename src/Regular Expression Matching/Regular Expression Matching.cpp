class Solution {
public:
    /*
    // Method 1: Recursive Solution: Exponential time complexity
    //
    // 1.   If the next character of p is NOT ‘*’, then it must match the 
    //      current character of s. Continue pattern matching with the 
    //      next character of both s and p.
    //
    // 2.   If the next character of p is ‘*’, then we do a brute force
    //      exhaustive matching of 0, 1, or more repeats of current 
    //      character of p… Until we could not match any more characters.

    // '.' Matches any single character.
    // '*' Matches zero or more of the preceding element.
    
    bool isMatch(string s, string p) {
        if (!p.size())
            return !s.size();
        
        // next char is not '*': must match current character
        if (p[1] != '*')
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
            
        // x* matches empty string or at least one character: x* -> xx*
        // next char is '*'
        while (!s.empty() && (p[0] == s[0] || p[0] == '.') )
        {
            if (isMatch(s,p.substr(2)))
                return 1;
            s = s.substr(1);
        }
        
        // One Scenario when this code gets hit is s=abbc p=z*abbc
        // i.e. x* matches empty string
        return isMatch(s, p.substr(2));
    }
    */
    
    // 2nd Method: Dynamic Programming. Difficult
    /*
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
    */
    bool isMatch(string s, string p) {
        if (!p.size())
            return !s.size();
        
        int m= s.size(), n = p.size();
        vector<vector<bool>> f(m+1, vector<bool>(n+1,0));
        
        f[0][0] = 1;
        
        // when pattern is empty
        for(int i=1; i<=m; i++)
            f[i][0] = 0;
            
        // When string is empty
        for(int i=1; i<=n; i++)
            f[0][i] = i>1 && p[i-1] == '*' && f[0][i-2];
            
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if (p[j-1] != '*')
                    f[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.') && f[i-1][j-1];
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && f[i-1][j];
            }
        }
        return f[m][n];
    }
};