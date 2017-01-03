class Solution {
public:
    /*
    // Method 1: Recursive, Exponential time. ~65ms
    // Its a very brute force approach
    // No intelligence used, just search for every permutations of string formed
    // of same length
    // The recursive way is quite simple.
    //    1) break the string to two parts: 
    //          s1[0..j]   s1[j+1..n]
    //          s2[0..j]   s2[j+1..n]
    //    2) then
    //          isScramble(s1[0..j], s2[0..j]) &&  isScramble(s1[j+1..n], s2[j+1..n])
    //        OR
    //          isScramble(s1[0..j], s2[j+1, n]) &&  isScramble(s1[j+1..n], s2[0..j])
    
    bool isScramble(string s1, string s2) {
        int l1= s1.length(), l2= s2.length();
        
        if (l1 != l2 || !l1 || !l2)
            return 0;
        
        if (s1 == s2)
            return 1;
            
        int cmap[26] = {0};
        for(int i=0; i<l1; i++)
        {
            cmap[s1[i] - 'a'] ++;
            cmap[s2[i] - 'a'] --;
        }
        for(int i=0; i<26; i++)
            if (cmap[i])
                return 0;
            
        for(int i=1; i<l1; i++)
        {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return 1;
            if (isScramble(s1.substr(0,i), s2.substr(l1-i)) && isScramble(s1.substr(i), s2.substr(0,l2-i)))
                return 1;
        }
        
        return 0;
    }
    */
    
    // Method 2: Dynamic Programming O(N^4): 3-d DP solution
    // It took 269ms here while recursion took ~65ms
    //*  Definition
    //*  
    //*      dp[k][i][j] means:
    //*  
    //*         a) s1[i] start from 'i'
    //*         b) s2[j] start from 'j'
    //*         c) 'k' is the length of substring
    //*  
    //*  Initialization     
    //*  
    //*      dp[1][i][j] = (s1[i] == s2[j] ? true : false)
    //*  
    //*  Formula
    //*  
    //*      same as the above recursive method idea
    //*  
    //*      dp[k][i][j] = 
    //*          dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ||
    //*          dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j]
    //*  
    //*      `divk` mean split the k to two parts, so 0 <= divk <= k;

    bool isScramble(string s1, string s2) {
        int l1= s1.length(), l2= s2.length();
        
        if (l1 != l2 || !l1 || !l2)
            return 0;
        
        if (s1 == s2)
            return 1;
            
        vector<vector<vector<bool>>> dp(l1+1, vector<vector<bool>> (l1, vector<bool> (l1,0)));
        
        // initialization k=1
        for(int i=0; i<l1; i++)
            for(int j=0; j<l1; j++)
                dp[1][i][j] = (s1[i] == s2[j]);
        
        // from k=2 onwards
        for(int k=2; k<=l1; k++)
        {
            // i should go upto l1-2 so that theres still a substring of length 1
            // is left on right side
            for(int i=0; i<l1-k+1; i++)
            {
                for(int j=0; j<l1-k+1; j++)
                {
                    for(int divk=1; divk<k && !dp[k][i][j]; divk++) 
                    {
                        dp[k][i][j] =( dp[divk][i][j] && dp[k-divk][i+divk][j+divk] ||
                                       dp[divk][i][j+k-divk] && dp[k-divk][i+divk][j] );
                    }
                }
            }
        }
        return dp[l1][0][0];
    }
};
