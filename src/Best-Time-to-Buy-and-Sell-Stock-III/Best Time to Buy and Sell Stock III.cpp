class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0)
            return 0;
        
        int maxp=0;
        int l=prices.size();
        
        vector<int> right(l);
        //right.push_back(0);
        
        int lowp=prices[0];
        int max=0;
        
        for(int i=1; i<l; i++)
        {
            if(max < (prices[i] - lowp) )
                max=prices[i] - lowp;
            
            lowp=prices[i] < lowp ? prices[i] : lowp;
            right[i]=max;
        }
        
        //can have used another array left similar to right array ,starting from end
        int highp=prices[l-1];
        max=0;
        
        for(int i=l-2; i>=0; i--)
        {
            if(max < ( highp - prices[i]) )
                max=highp-prices[i];
            
            if(maxp < ( right[i] + max ) )
                maxp=right[i] + max;
                
            highp=prices[i] > highp ? prices[i] : highp;
        }
        return maxp;
        
    }
};
