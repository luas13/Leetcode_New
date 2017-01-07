class Solution {
public:
    // Algo is 2 step process:
    // 1) Create a ispalin_table which where ispalin_table[i][j]
    // means whether string[i..j] is palindrome or not
    // 2) Create a 1d mincut[] which stores min no of cut upto
    // string[0..i]
    int minCut(string s) {
        int l= s.size();
        if (!l || l==1)
            return 0;
        if (l==2)
            return (s[0] == s[1] ? 0 : 1);
            
        vector<vector<int>> ispalin_table(l, vector<int>(l, 0));
        for(int i=0; i<l-1; i++)
        {
            ispalin_table[i][i] = 1;
            ispalin_table[i][i+1] = (s[i] == s[i+1] ? 1 : 0);
        }
        ispalin_table[l-1][l-1] = 1;
        
        for(int len= 3; len <= l; len++)
        {
            for(int i=0; i<=l-len; i++)
            {
                if(s[i] == s[i+len-1] && ispalin_table[i+1][(i+len-1)-1])
                    ispalin_table[i][i+len-1] =1;
            }
        }
        
        // if s[0..i] isn't palindrome 
        // then, for each 0 to i, find a "j" which meets two conditions:
        //    a) s[j+1..i] are palindrome.
        //    b) res[j]+1 is minimal   
        // Initialise, mincut cant be greater than string's length 
        vector<int> mincut(l, l-1);
        
        for(int i=0; i<l; i++)
        {
            if (ispalin_table[0][i])
                mincut[i] = 0;
            else
            {
                int minc = l-1;
                for(int j=0; j<i; j++)
                {
                    if (ispalin_table[j+1][i])
                        minc = min(minc, mincut[j]+1);
                }
                mincut[i] = minc;
            }
        }
        return mincut[l-1];
    }
};