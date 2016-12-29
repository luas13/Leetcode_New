/*
buy[i] : Maximum profit which end with buying on day i or end
with buying on a day before i and takes rest until the day i since then.

sell[i] : Maximum profit which end with selling on day i or end
with selling on a day before i and takes rest until the day i since then.

Define Recursion
buy[i]: To make a decision whether to buy at i, we either take a rest, by just using the old decision at i - 1, or sell at/before i - 2, then buy at i, We cannot sell at i - 1, then buy at i, because of cooldown.

sell[i]: To make a decision whether to sell at i, we either take a rest, by just using the old decision at i - 1, or buy at/before i - 1, then sell at i.

So we get the following formula:

buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);   
sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);

First we define the initial states at i = 0:
We can buy. The max profit at i = 0 ending with a buy is -prices[0].
We cannot sell. The max profit at i = 0 ending with a sell is 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (l == 0)
            return 0;
            
        //b1 represents buy[i-1], b0 represents buy[i]
        //s2 represents sell[i-2], s1 represents sell[i-1], s0 represents sell[i]
        
        int b1= -prices[0], b0;
        int s2 = 0, s1=0, s0;
        
        for (int i=1; i<l; i++)
        {
            b0 = max(b1, s2-prices[i]);
            s0 = max(s1, b1 + prices[i]);
            
            b1 = b0;
            s2 = s1;
            s1 = s0;
        }
        
        return s0;
    }
};