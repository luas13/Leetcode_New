/*
Bottom Up Approach

Base  conditons:         
D(i,0) =i   D(0,j) = j

Termination:  D(m,n)

 D(i,j)= min { D(i-1,j) + 1 ,                                                          //Deletion
               D(i,j-1) + 1 ,                                                          //Insertion
               D(i-1,j-1) + 1;  if X(i) ≠ Y(j) otherwise nothing to be added           //Replace
             }
               

A = [A1, A2,…, An]
B = [B1, B2,…, Bm]

Notice that the lengths of A and B (n and m respectively) might be different.

We define the state dp[i][j] to be the minimum number of operations to convert word1[0..i - 1] to word2[0..j - 1].

We know that in the end, both strings will need to have the same length and match their characters on each position. 
So, if we take just the first character of A and B, what choices do we have? We have 3 different transformations that 
we can apply so we have 3 choices as well:

1)We can replace the first character of A by the first character of B. The cost of doing this replacement will be 1 
if the characters are different and 0 if they are equal (because in that case we don’t need to do anything). 
At this point we know that both strings start with the same character so we can compute the edit distance of 
A[1..n] = [A1,…, An] and B[1..m] = [B1,…, Bm]. The final result will be the cost of transforming A[0] into B[0] plus 
the edit distance of the remaining substrings.

2)The second choice we have is inserting a character into A to match the character in B[0], which has a cost of 1. 
After we have done this, we still need to consider the original A string because we have added a new character to it 
but we haven’t process any of its original characters. However, we don’t need to consider B[0] anymore because we know 
that it matches A[0] at this point. Therefore, the only thing we need to do now is to compute the edit distance of the
original A and B[1..m] = [B1,…, Bm]. The final result will be this value plus 1 (the cost of inserting the character 
into A).

3)The last case is symmetrical to the previous one. The third transformation we can apply is simply to delete A[0]. 
This operation has a cost of 1 as well. After doing this, we have consumed one character of A but we still have all 
the original characters of B to process. So we simply need to compute the edit distance of A[1..n] = [A1,…, An] and B.
Again, the final value of the edit distance will be this value plus 1 (the cost of deleting A[0].

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
    
    int m= word1.length();
    int n= word2.length();
    
    if(m==0 && n==0)
        return 0;
        
    if( m == 1 && n==1) 
    {
        if( word1[0] == word2[0] )
            return 0;
        return 1;
    }
    
    vector< vector<int> > dp(m+1, vector<int> (n+1));
    
    //base cases when 1 string is empty and other has a length of l then obviously it will take l minDistance
    
    for(int i=0; i<=n; i++)
    {
        dp[0][i]= i;
    }

    
    for(int i=0; i<=m; i++)
    {
        dp[i][0]= i;
    }

    int val_i, val_d, val_r;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            val_i = dp[i][j-1] + 1;                          //value corresponding to insertion
            val_d = dp[i-1][j] + 1;                          //value corresponding to deletion

            val_r = ( word1[i-1] != word2[j-1] ) ? dp[i-1][j-1] + 1 : dp[i-1][j-1] ;     //value corresponding to replace

            dp[i][j] = min ( min( val_i, val_d ) , val_r);
        }
    }

    return dp[m][n];
        
    }
};


// Solution 2
/*
This is a classic problem of Dynamic Programming. We define the state 
dp[i][j] to be the minimum number of operations to convert 
word1[0..i - 1] to word2[0..j - 1]. The state equations have two cases: 
the boundary case and the general case. Note that in the above notations, 
both i and j take values starting from 1.

For the boundary case, that is, to convert a string to an empty string, 
it is easy to see that the mininum number of operations to convert 
word1[0..i - 1] to "" requires at least i operations (deletions). 
In fact, the boundary case is simply:

dp[i][0] = i;
dp[0][j] = j.
Now let's move on to the general case, that is, convert a non-empty 
word1[0..i - 1] to another non-empty word2[0..j - 1]. Well, let's 
try to break this problem down into smaller problems (sub-problems). 
Suppose we have already known how to convert word1[0..i - 2] to word2[0..j - 2], 
which is dp[i - 1][j - 1]. Now let's consider word[i - 1] and word2[j - 1]. 
If they are euqal, then no more operation is needed and dp[i][j] = dp[i - 1][j - 1]. 
Well, what if they are not equal?

If they are not equal, we need to consider three cases:

Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1] (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
Make sure you understand the subtle differences between the equations for deletion and insertion. 
For deletion, we are actually converting word1[0..i - 2] to word2[0..j - 1], 
which costs dp[i - 1][j], and then deleting the word1[i - 1], which costs 1. The case is similar for insertion.

Putting these together, we now have:

dp[i][0] = i;
dp[0][j] = j;
dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
The above state equations can be turned into the following code directly.
*/
 
class Solution { 
public:
    int minDistance(string word1, string word2) { 
        int m = word1.length(), n = word2.length();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;  
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
        return dp[m][n];
    }
};
