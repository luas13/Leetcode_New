/*
Given any day I, its max profit status boils down to one of the two status below:

(1) buy status:
buy[i] represents the max profit on day i in buy status, given that the last action you took is a buy action on day K, where K<=i. And you have the right to sell on day i+1, or do nothing.

(2) sell status:
sell[i] represents the max profit on day i in sell status, given that the last action you took is a sell action on day K, where K<=i. And you have the right to buy at day i+1, or do nothing.

Let's walk through from base case.

Base case:
We can start from buy status, which means we buy stock on day 0.
buy[0]=-prices[0];

Or we can start from sell status, which means we sell stock at day 0.
Given that we don't have any stock at hand on day 0, we set sell status to be 0.
sell[0]=0;

Status transformation:
On day i, we may buy stock (from previous sell status) or do nothing (from previous buy status):
buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]);

Or

On day i, we may sell stock (from previous buy status) or keep holding (from previous sell status):
sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);

Finally:
We will return sell[last_day] as our result, which represents the max profit on the last day, given that you took sell action at any day before the last day.

We can apply transaction fee at either buy status or sell status.
*/

/*
Detailed Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l = prices.size();
        if (!l)
            return 0;
        
        vector<int> buy(l, 0);
        vector<int> sell(l, 0);
        
        buy[0] = -prices[0];
        sell[0] = 0;
        
        for(int i=1; i<l; i++)
        {
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]);    
            sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee);
        }
        
        return sell[l-1];
    }
};

*/

// Optimized solution, take a look, if you understand the above concept
// you will find, you dont need an array for buy and sell
// but just two variables, buy and sell
// Use this method only if you understand the above solution

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l = prices.size();
        if (!l)
            return 0;
        
        int buy, sell;
        
        buy = -prices[0];
        sell = 0;
        int prev_buy = 0;
        
        for(int i=1; i<l; i++)
        {
            prev_buy = buy;
            buy = max(buy, sell - prices[i]);    
            sell = max(sell, prev_buy + prices[i] - fee);
        }
        
        return sell;
    }
};