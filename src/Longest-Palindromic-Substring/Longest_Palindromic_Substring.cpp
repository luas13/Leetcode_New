//Using Manacher's Algorithm
class Solution {
public:
    string preProcessString(string s)
    {
        int n = s.length();
        if (n == 0) return "^$";
        string ret;
        ret = "^";
        for (int i=0; i<n; i++)
            ret += "#" + s.substr(i, 1);

        ret += "#$";
        return ret;
    }

    string longestPalindrome(string s) {
        //int n = s.length();
        string t = preProcessString(s);
        int t_len = t.length();
        
        // Initialise all to 0
        vector<int> p(t_len, 0);
        
        // Initially Right boundary, Centre and i all points to 1st
        // index charcter of processed string
        int R = 1;
        int C = 1;

        // C - Centre of main Palindrome that is into consideration
        // R - Right boundary of main palindrome
        // i - Its for finding centre for next main palindrome
        // mirr - mirror location for i
        
        for(int i=1; i<t_len-1; i++)
        {
            int mirr = 2*C - i;     // C - (i-C)

            // Initial minimum len which can be calculated using previous calculation
            // Only if i lies within Right boundary of main palindrome
            if (i<R)
                p[i] = min(p[mirr], R-i);

            //Expansion further to find actual length of palindrome centered at i if possible
            while (t[i + (1+p[i])] == t[i - (1+p[i])])
                p[i] ++;

            //If palindrome centered at i expand past R,
            //Update right boundary and new centre of palindrome
            if (i + p[i] > R)
            {
                R = i + p[i];
                C = i;
            }
        }

        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < t_len-1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
};


/*
class Solution {
public:
    // O(N*N) Solution: Expanding around Centres
    // Centre being each character and the empty space in between
    string expandAroundCentre(string s, int c1, int c2){
        int n = s.length();
        int l = c1;
        int r = c2;
        while(l>=0 && r<=n-1 && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-1-l);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)
            return ("");
        string longest = s.substr(0,1);
        for(int i=0; i<n-1; i++){
            string s1 = expandAroundCentre(s, i, i);
            if (s1.length() > longest.length())
                longest = s1;
        }
        for(int i=0; i<n-1; i++){
            string s1 = expandAroundCentre(s, i, i+1);
            if (s1.length() > longest.length())
                longest = s1;
        }
        return longest;
    }
};
*/