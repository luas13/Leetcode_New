class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (!l || l==1) 
            return 0;
        
        int minv = INT_MAX;
        int maxprofit = 0;
        
        for(int i=0; i<l; i++)
        {
            if (prices[i] >= minv)
                maxprofit += prices[i] - minv;
            
            minv = prices[i];
        }
        
        return maxprofit;
    }
};


____________________________________________________________________________________________________
//Simple Code Method-1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if (l == 0 || l==1)
            return 0;
        int min = prices[0];
        int max_diff = 0;
        for (int i=1; i<l; i++)
        {
            if (prices[i] > min)
                max_diff += prices[i] - min;
            //think of a zig zag graph, in any case minimum will get updated 
            //either its increasing or decreasing
            min = prices[i];
        }
        return max_diff;
    }
};



___________________________________________________________________________________

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp=0;
        int s,e;
        
        int l=prices.size();
        if(l == 0 || l == 1)
            return maxp;
            
        
        for(int i=0; i<l; i++)
        {
            s=i;
            while( (i+1) < l && prices[i+1] < prices[i] )
            {
                s=i+1;
                i++;
            }
            if( (i+1) >= l )
                return maxp;
                
            e=i;
            while( (i+1) < l && prices[i+1] > prices[i] )
            {
                e=i+1;
                i++;
            }
            //if( (i+1 >= l) )
                //return maxp;
                
            maxp+= prices[e] - prices[s];
            
        }
        return maxp;
        
    }
};
