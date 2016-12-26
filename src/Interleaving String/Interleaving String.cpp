/*
Thanks to Haoel.

for eg. 
s1 = aa
s2 = ab
s3 = aaba

      0  1   2  
   ------------
  |  |0 |a | b|  -> String 2
0 |0 |T |T | F|  -> String 2 active while String 1 considered empty. Similarily vertically S2 empty.
1 |a |T |T | T|  -> String 2 active while String 1 considered 1 char string. 
2 |a |T |F | T|
   ------------
 |
 string 1

ilpossible[1][1] assumes that EITHER 1st char of s1 has matched with 1st char of s3 so
is 1st char of s2 matching with 2nd char of s3 OR 1st char of s2 has matched with 1st 
char of s3 so is 1st char of s1 matching with 2nd char of s3. then only interleaving is
possible. This idea is interpolated.

Each cell, lets say ilpossible[1][2] means whether "a" and "ab" can interleave to make "aab"
ilpossible[1][2] = either
    1)  if s1[0] == s3[2] then ilpossible[0][2] means just by ignoring s1[0] i.e. 'a' is it possible to 
        interleave with s2[0,1] to make s3[0,1]
    2)  if s2[1] == s3[2] then ilpossible[1][1] means just by ignoring s2[1] i.e. 'b' is it possible to 
        interleave with s1[0] to make s3[0,1]

Extra:
Considering:
    s1 = a1, a2 ........a(i-1), ai
    s2 = b1, b2, .......b(j-1), bj
    s3 = c1, c3, .......c(i+j-1), c(i+j)
Defined 
    
    ilpossible[i][j]  means   s1[0..i] and s2[0..j] interleaves to make string S3[0..i+j]
    So, if ai == c(i+j), then ilpossible[i][j] = ilpossible[i-1][j], which means
        s1 = a1, a2 ........a(i-1)
        s2 = b1, b2, .......b(j-1), bj
        s3 = c1, c3, .......c(i+j-1)
    Same, if bj = c(i+j), then ilpossible[i][j] = ilpossible[i][j-1];
Formula:
    ilpossible[i][j] = 
        (s3[i+j-1] == s1[i]) && ilpossible[i-1][j] || 
        (s3[i+j-1] == s2[j]) && mailpossibletch[i][j-1]
Initialization:
    i=0 && j=0, ilpossible[0][0] = true;
    i=0,   s3[j] == s2[j], ilpossible[0][j] |= ilpossible[0][j-1]
           s3[j] != s2[j], ilpossible[0][j] = false;
    j=0,   s3[i] == s1[i], ilpossible[i][0] |= ilpossible[i-1][0]
           s3[i] != s1[i], ilpossible[i][0] = false;

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if (l1 + l2 != l3)
            return false;
        
        vector<vector<bool>> ilpossible(l1+1, vector<bool>(l2+1, false));
        ilpossible[0][0] = true;
        
        for (int i=1; i<=l1; i++)
        {
            if (s1[i-1] == s3[i-1])
                ilpossible[i][0] = true;
            else
                break;
        }
        
        for (int i=1; i<=l2; i++)
        {
            if (s2[i-1] == s3[i-1])
                ilpossible[0][i] = true;
            else
                break;
        }
        
        for (int i=1; i<=l1; i++)
        {
            for (int j=1; j<=l2; j++)
            {
                if (s1[i-1] == s3[i+j-1])
                    ilpossible[i][j] = ilpossible[i][j] || ilpossible[i-1][j];
                    
                if (s2[j-1] == s3[i+j-1])
                    ilpossible[i][j] = ilpossible[i][j] || ilpossible[i][j-1];
            }
        }
        return ilpossible[l1][l2];
    }
};

/*
//Recursive Solution...Time Limit Exceeded
bool isInterleave_dfs(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    const char *p1 = s1.c_str(), *p2 = s2.c_str(), *p3 = s3.c_str();
    for (; *p3 != '\0'; p3++){
        if (*p3 == *p1 && *p3!=*p2) {
            p1++;
        }else if ( *p3 == *p2 && *p3 != *p1) {
            p2++;
        }else if (*p3==*p1 && *p3 ==*p2) {
            if (isInterleave(p1+1, p2, p3+1) == false){
                return isInterleave(p1, p2+1, p3+1);
            }
            return true;
        }else{
            return false;
        }
    }
    return ( *p1 =='\0' && *p2 =='\0' && *p3 =='\0' );
}
*/