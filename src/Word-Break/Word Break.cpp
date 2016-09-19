/*
*   In case of unsorted_set,O(n) is the worst running time of search when all the elements are in the same bucket.
*   Make a table dp, such that, dp[i] means if s[0..i-1] can be segmented.
*   dp[i+1] = dp[j] is true && s[j..i] in dict, for j = 0..i

*   dict = ["leet", "code"]
*   s = "leetcode"

    
      0 1 2 3 4 5 6 7
      l e e t c o d e
 
     dp Table:
      0 1 2 3 4 5 6 7 8   Index i
      1 0 0 0 1 0 0 0 1
      
*   for i=0  dp[0] && 'l'in dict
*   for i=1  dp[0] && 'le'in dict  || dp[1] && 'e'in dict
*   for i=2  dp[0] && 'lee'in dict  || dp[1] && 'ee'in dict || dp[2] && 'e'in dict
*   for i=3  dp[0] && 'leet'in dict  || dp[1] && 'eet'in dict || dp[2] && 'et'in dict || dp[3] && 't'in dict
    
*   At this point dp[0] && 'leet'in dict yeilds 1 and dp[3+1] becomes 1
    
*   for i=4  dp[0] && 'leetc'in dict  || dp[1] && 'eetc'in dict || dp[2] && 'etc'in dict || dp[3] && 'tc'in dict
            || dp[4] && 'c'in dict
            
    and so on...
*/


class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int i=0,l=s.length();
        if(l == 0)
        return false;
        
        if(l == 1)
            return ( dict.find( s ) != dict.end() );
            
        vector<int> dp(l+1,0);
        dp[0]=1;
        
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if( dp[j]  &&  dict.find( s.substr(j, i-j+1) ) != dict.end() )
                {
                    dp[i+1]=1;
                    break;
                }
            }
        }
        
        return dp[l];
        
    }
};
