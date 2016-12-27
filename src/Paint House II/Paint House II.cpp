/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain
color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost
of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost 
to paint all houses.

Note
All costs are positive integers.

Follow up: Could you solve it in O(nk) runtime?
*/

// Below solution has not passed OJ
// Beautiful explanation : http://www.cnblogs.com/airwindow/p/4804011.html

// Top down DP solution using min_1 and min_2 of previous row
// we decide to paint house "i" with color "j", we can compute the minimum cost of other colors at "i-1" stage through following way.
// case 1: iff "color[i-1][j] == min_1", it means the min_1 actually records the minimum value of color[i-1][j] (previous color is j),
// we have to use min_2;
// case 2: iff "color[i-1][j] != min_1", it means min_1 is not the value of color[i-1][j] (previous color is not j), we can use the
// min_1's color.

//OR, other way to think

//we can also define DP[i][j] as the minimum cost to paint house until i with color j. 
//Then DP[i][j] = cost[i][j] + min({DP[i - 1][m] | m = 0, 1, 2, …., k and m != j }). We can use an variable preMin to record 
//the minimum cost of DP[i – 1] [m], and the corresponding color minColor. 
//One problem is that the minColor (color k with minimum value) can equal to the current color.  In this case we need to use
//the color with second smallest cost. So define another variable secondMin to record the second minimum cost of DP[i – 1][m]
//along with the corresponding color secondMinColor. 


class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) 
	    return 0;
		
        int r = costs.size(), c = costs[0].size();
        int first_min_prevrow = 0;
	int second_min_prevrow = 0;
	int prev_min1, prev_min2;
	vector<int> dp(c, 0);
		
        for (int i = 0; i < n; i++) 
	{
	    prev_min1 = first_min_prevrow;
	    prev_min2 = second_min_prevrow;
			
	    first_min_prevrow = INT_MAX;
            second_min_prevrow = INT_MAX;
			
            for (int j = 0; j < c; j++) 
	    {
                if (dp[j] != prev_min1 || prev_min1 == prev_min2)
		    dp[j] = costs[i][j] + prev_min1;
		else
		    dp[j] = costs[i][j] + prev_min2;
            }
			
	    if (dp[j] <= first_min_prevrow)
	    {
		second_min_prevrow = first_min_prevrow;
		first_min_prevrow = dp[j];
	    }
	    else if (dp[j] < second_min_prevrow)
		second_min_prevrow = dp[j];
        }
        return first_min_prevrow;
    }
};
