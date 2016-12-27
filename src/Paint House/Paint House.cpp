/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note
All costs are positive integers.
*/


//Since its locked question. It hasn't passed OJ.

//Recursive way of thinking
int fin(int cost[][], int index, int r, int v)
{
	if (r == cost.size())
		return v;
	
	else
	{
		return ( v + min( fin(cost, index, r+1, cost[r][(index - 1)%3]),
						  fin(cost, index, r+1, cost[r][(index + 1)%3]) )
	}
}

int fun(int cost[][])
{
	return min3( fin(cost, 0, 1, cost[0][0]),
				 fin(cost, 1, 1, cost[0][1]),
				 fin(cost, 2, 1, cost[0][2]) );
}


//DP Solution... Bottom Up solution. Top down can also be done similarily
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
		int R= costs.size();
		int C= costs[0].size();
		if (!R)
			return 0;
		if (R==1)
			return min(cost[0][0], min(cost[0][1], cost[0][2]));
			
		vector<vector<int>> dp(R, vector<int>(C,0))
		for (int i= R-1; i>=0; i--)
		{
			for (int j=C-1; j>=0; j--)
			{
				if (i == R-1)
					dp[i][j] = costs[i][j];
				else
				{
					dp[i][j] = cost[i][j] + min( dp[i+1][(j-1)%3], dp[i+1][(j+1)%3] );
				}
			}
		}
		return min(dp[0][0], min(dp[0][1], dp[0][2]));
	}
};