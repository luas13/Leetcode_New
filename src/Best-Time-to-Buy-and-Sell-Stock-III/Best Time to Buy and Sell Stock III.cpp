/*
Time: 8ms
Create the max u can get upto any index coming from right to left in 
rightmax array. Traverse from left to right and check if u can get 
max upto any index(from left upto that point) + rightmax[same index]
*/
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (!l || l==1)
            return 0;
        
        vector<int> rightmax(l, 0);
        int maxprofit = 0;
        
        int maxv = prices[l-1];
        for(int i=l-2; i>=0; i--)
        {
            rightmax[i] = max(rightmax[i+1], maxv - prices[i]);
            maxv = max(maxv, prices[i]);
        }
        
        int minv = prices[0];
        for(int i=1; i<l; i++)
        {
            
            if (prices[i] >= minv)
                maxprofit = max(maxprofit, prices[i] - minv + rightmax[i]);
            
            minv = min(minv, prices[i]);
        }
        return maxprofit;
    }
};



____________________________________________________________________________________________
Time: 14 ms
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
