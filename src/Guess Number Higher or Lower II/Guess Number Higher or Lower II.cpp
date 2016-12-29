/*
The example description should be:

first introduce best strategyto guess:

for one number, like 1, best strategy is 0$
for two number, like 3,4, best strategy is 3$, which can be understood in this way: you have two way to guess:
 a) start by guess 4 is the target, (the worst case is) if wrong, you get charged $4, then immediately you 
 know 3 is the target number, get get charged $0 by guessing that, and finally you get charged $4. b) 
 similarly, if you start by 3, (the worst case is) if wrong, you get charged $3, then you immediately 
 know that 4 is the target number, and get charged $0 for guessing this, and finally you get charged $3.
 In summary:
range ---------> best strategy cost
3, 4 ---------> $3
5, 6 ---------> $5
...
for three number, the best strategy is guess the middle number first, and (worst case is) if wrong, 
you get charged that middle number money, and then you immediately know what target number is by 
using "lower" or "higher" response, so in summary:

range ---------> best strategy cost
3, 4, 5 ---------> $4
7, 8, 9 ---------> $8
...
"for more numbers", it can simply be reduced them into smaller ranges, and here is why DP solution 
make more sense in solving this.
suppose the range is [start, end]
the strategy here is to iterate through all number possible and select it as the starting point, say
 for any k between start and end, the worst cost for this is: k+DP( start, k-1 ) + DP(k+1, end ), and
 the goal is minimize the cost, so you need the minimum one among all those k between start and end.
 
 
OR

Let’s take an instance, for n = 3, we have 3 choices either to choose 1 or 2 or 3.
Let’s say we choose 1. There are 2 possible chances,

[Case X]: 1 is the actual number so you pay 0$ or,
[Case Y]: 1 is not the actual number so you pay 1$ (now you know that the actual number is > 1 
because for every guess we will know if its less than or greater than, in our case it can only 
be greater than) and have the subproblem (2, 3). To choose from (2, 3) again recursively applying
 the same method, you can choose either 2 or 3. If you pick 2, you have 2 possible outcomes again.
 2 is the actual number and you pay 0$ for this choice or 2 is not the actual number and you pay 2$
 for this choice and you know 3 is the answer since that’s the only one left. On the other hand, 
 if you had picked 3, then either 3 is correct or you pay 3$ and know 2 is the actual answer since
 it’s the only one left. So to sum up this, you pay 2$ in the worst case if you choose 2 or pay 3$
 in the worst case if you pick 3$. So we will pick the min of the worst cases which is 2$ and hence
 2 is the answer for (2, 3) subproblem. (Notice the minimax?)
      So, the total cost paid in this is 1$ + 2$ = 3$.

Let’s say you picked 2 initially. You have 2 possible outcomes.

    2 is the actual number and you pay 0$ or,
    2 is not the actual number and you pay 2$. At this point, you get to know if the actual 
    number is less than or greater than the actual number. So, you will know the answer right
    away without another guess. So you end up paying 2$.
    So, if you choose 2 initially, you risk paying 2$ at most.
    Similarly, if you had chosen 3 initially, you risk paying 4$ at most. Hence picking 2 
    initially is the best option and you risk at most 2$.

This leads to a natural recursion, which you can find in the code below. I have memoized it in a matrix.
*/

class Solution {
public:
    // Just think about the case n=3 i.e. {1,2,3} and write the code
    // Between start and end explore all the options to findmin()
    // Similarity with minmax problem
    // Basically we are returning minimum of all the cases when starting point 
    // is 1 or 2 or 3
    int findmin(vector<vector<int>>& dp, int start, int end)
    {
        if (start >= end)
            return 0;
        if (dp[start][end] != INT_MAX)
            return dp[start][end];
        for(int i=start; i<= end; i++)
        {
            dp[start][end] = min(dp[start][end], i + max(findmin(dp, start, i-1), findmin(dp, i+1, end)));
        }
        return dp[start][end];
    }
    int getMoneyAmount(int n) {
        if (n<= 0)
            return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1,INT_MAX));
        return findmin(dp, 1, n);
    }
};