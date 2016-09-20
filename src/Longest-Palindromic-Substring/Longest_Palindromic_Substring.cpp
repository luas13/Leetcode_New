/*
 * O(N^2) solution by expanding around centre 
 */

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

class Solution {
public:
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
