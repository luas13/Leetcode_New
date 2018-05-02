// Soln2: A bit cleaner
// Bottom up approach, Top down is quite complex
// Bootom up Intution: Path to be taken depends upon the future demons 
// seen on the way to princess
// dp[i][j] represents the min health needed at position (i, j)
// We add extra row & column to make it cleaner & initialize with INT_MAX

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        if (!r)
            return 0;
        int c = dungeon[0].size();
        
        vector<vector<int>> dp(r+1, vector<int> (c+1, INT_MAX));
        dp[r][c-1] = 1;
        dp[r-1][c] = 1;
        int need;
        
        for(int i=r-1; i>=0; i--)
        {
            for (int j=c-1; j>=0; j--)
            {
                need = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        
        return dp[0][0];
    }
};

/*
This code changes the dungeon array so to avoid it ,you can copy it first.
Note: A Bottom-Up approach.
For every cell starting from end "find minimum health required to enter this cell".
For eg. dungeon array

   0     1     2
+-----+-----+-----+
| -2  | -3  |  3  |  0
+-----+-----+-----+
| -5  | -10 |  1  |  1
+-----+-----+-----+
| 10  | 30  | -5  |  2
+-----+-----+-----+

Here dungeon[2][2] = -5 so u need 1-(-5)=6 health points to enter this cell.So dungeon[2][2] becomes 6.If this cell 
was 5 u just needed 1 health point to enter this cell.

Then go on to calculate other cell values.Whenever that minimum health required becomes <= 0 ,you have to insert 1 
to that cell(think,the value is becoming <= 0 ,because the present cell might be providing enough +ve health,so to 
enter such cells you just need a health point of 1 only ).

In the above eg. 
For dungeon[1][2], u need 6-1=5 health points to enter this cell.

For dungeon[2][1], u need 6-(30)=-24 health points to enter this cell.Since its negative bcz we have 
got huge +ve health present in this cell already so we just need 1 health point to enter this cell.

For dungeon[1][1], u need 5-(-10)= 15 health points if u wish to go right from dungeon[1][1] and 1-(-10)= 11 health 
points if u wish to go down from dungeon[1][1].Both this path were ultimately lead to destination.Now here we will
choose that cell which requires min health point requirement i.e. down cell,so at this point 
dungeon[1][1] = min(15 , 11) =11

Finally the output cell is as follows:

   0     1     2
+-----+-----+-----+ 
|  7  |  5  |  2  |  0
+-----+-----+-----+
|  6  | 11  |  5  |  1
+-----+-----+-----+
|  1  |  1  |  6  |  2
+-----+-----+-----+

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        
        dungeon[m-1][n-1] = ( 1 - dungeon[m-1][n-1]) <= 0 ? 1 : 1 - dungeon[m-1][n-1];
        
        //fill values in last column
        for(int i=m-2 ; i>=0 ; i--)
            dungeon[i][n-1] = ( dungeon[i+1][n-1] - dungeon[i][n-1]) <= 0 ? 1 : dungeon[i+1][n-1] - dungeon[i][n-1];
            
        //fill values in last row
        for(int j=n-2 ; j>=0 ; j--)
            dungeon[m-1][j] = ( dungeon[m-1][j+1] - dungeon[m-1][j]) <= 0 ? 1 : dungeon[m-1][j+1] - dungeon[m-1][j];
            
        for(int i=m-2 ; i>=0 ; i--)
        {
            for(int j=n-2 ; j>=0 ; j--)
            {
                dungeon[i][j] = min( dungeon[i+1][j] - dungeon[i][j] , dungeon[i][j+1] - dungeon[i][j]);
                dungeon[i][j] = dungeon[i][j] <= 0 ? 1 :dungeon[i][j];
            }
        }
        
        return dungeon[0][0];
        
    }
};
