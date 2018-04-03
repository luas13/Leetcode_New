/*
Check http://www.geeksforgeeks.org/number-of-ways-to-make-mobile-lock-pattern/

Given Android 9 key lock screen and numbers m and n, where 1 <= m <= n <= 9 .
Count the total number of patterns of Android lock screen, which consist of minimum of m keys and maximum n keys.
Rules for valid pattern

    Each pattern must connect at least m keys and at most n keys
    All the keys must be distinct
    If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed
    The order of keys used matters.


Example:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Valid move : 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it pass through key 5, which has been already selected in the pattern
Valid move : 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it pass through key 2, which has been already selected in the pattern
Invalid move : 4 - 1 - 3 - 6
Line 1 - 3 pass through key 2 which is not still selected in the pattern
Invalid move : 4 - 1 - 9 - 2
Line 1 - 9 pass through key 5 which is not still selected in the pattern
*/

class Solution{
public:
	int countfromcurr(int jumps[][], int visit[], int curr, int len)
	{
		if (len <= 0)
			return len == 0 ? 1 : 0;

		int ways = 0;
		visit[curr] = 1;

		for (int i =1; i<=9; i++)
			// if its not visited and (either its adjacent index or the index
            // is already visited)
			if (!visit[i] && (!jumps[curr][i] || visit[ jumps[curr][i] ]))
				ways += countfromcurr(jumps, visit, i, len-1);
		
		visit[curr] = 0;

		return ways;
	}

	int count(int m, int n)
	{
		if (n==0)
			return 0;
		// Save what all comes in between if you jump from i to j
		// on 3x3 pattern
		int jumps[10][10] = {0};
		jumps[1][3] = jumps[3][1] = 2;
		jumps[3][9] = jumps[9][3] = 6;
		jumps[9][7] = jumps[7][9] = 8;
		jumps[7][1] = jumps[1][7] = 4;
		
		jumps[1][9] = jumps[9][1] = jumps[2][8] = jumps[8][2] = jumps[3][7] = jumps[7][3] = jumps[4][6] = 5;

		//A visited matrix so that you can move through this index only if its visited
		int visit[10] = {0};
		int ways = 0;

		for (int i=m; i<=n; i++)
		{
			// Symmetry for 1, 3, 7, 9
			ways += 4 * countfromcurr(jumps, visit, 1, i-1);
			// Symmetry for 2,4,6,8
			ways += 4 * countfromcurr(jumps, visit, 2, i-1);
			// Only one way for 5 as its unique 
			ways  = countfromcurr(jumps, visit, 5, i-1);
		}
		return ways;
	}

};
