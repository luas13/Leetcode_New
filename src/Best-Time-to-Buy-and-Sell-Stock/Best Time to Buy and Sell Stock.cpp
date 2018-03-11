class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (!l || l==1) 
            return 0;
        
        int minv = INT_MAX;
        int maxdiff = 0;
        
        for(int i=0; i<l; i++)
        {
            if (prices[i] < minv)
                minv = prices[i];
            if (prices[i] >= minv)
                maxdiff = max(prices[i] - minv, maxdiff);
        }
        
        return maxdiff;
    }
};


---------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int min=0,maxd=0;
        int buy=0,sell=0,diff=0;
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < prices[min])
                min=i;
                
            diff=prices[i] - prices[min];
            if(diff > maxd)
            {
                maxd=diff;
                buy=min;
                sell=i;
            }
        }
        return maxd;
        
    }
};
