//if k >= prices.size()/2, we can have transactions any time, it can be solved by O(n). else DP

// dpProfit[t][i]: maximum Profit using at most t transactions up to day i (including day i)
// dpProfit[t][i] = max(dpProfit[t][i - 1], prices[i] - prices[j] + dpProfit[t - 1][j]) for all j in range [0, i - 1]
//                = max(dpProfit[t][i - 1], prices[i] + max(dpProfit[t - 1][j] - prices[j])) for all j in range [0, i - 1]
//                = max(dpProfit[t][i - 1], prices[i] + max( prev [t - 1] trans's profit at the corresponding j in range [0, i - 1]    //                                                           minus price[j] )  )

class Solution {
public:
    int maxProfit_all(vector<int> &prices) {
        int n = prices.size();
        int sum = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i-1]){
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    
    int maxProfit(int k, vector<int> &prices) {
        int l=prices.size();
        if(l <= 1 || k==0)
            return 0;
        
        if(k >= l/2)
            return maxProfit_all(prices); 
            
        int tmpmax;
        int t;                                                   // number of transactions
        vector< vector<int> > dpProfit( 2, vector<int>(l,0) ); //initialises vector of vector =0 
        
        /*If k is very large then creating vector of vector may cause runtime error,so to optimize, u just need
        dpProfit[2][l] because you dont need the intermediate values.You can change the dpProfit array because all u 
        need is the end value.Draw a figure to understand.(for t=3,it just need values of array corresponding to t=2 
        and not values of t=1,so u can overwrite values.To simplyfy first wirte the code without this optimization in
        mind and change t with t%2 and t-1 with (t+1)%2 ).
        
        for(t=1; t<=k; t++)
        {
            tmpmax=dpProfit[t-1][0] - prices[0];
            
            for(int i=1; i<l; i++)
            {
                dpProfit[t][i] = max(dpProfit[t][i-1] , prices[i] + tmpmax);
                tmpmax= max (tmpmax, dpProfit[t-1][i] - prices[i] );
            }
        }
        return dpProfit[t][l-1];
        */
        
        for(t=1; t<=k; t++)
        {
            tmpmax=dpProfit[ (t+1)%2 ][0] - prices[0];
            
            for(int i=1; i<l; i++)
            {
                dpProfit[ t%2 ][i] = max(dpProfit[ t%2 ][i-1] , prices[i] + tmpmax);
                tmpmax= max (tmpmax, dpProfit[ (t+1) %2][i] - prices[i] );
            }
        }
        return dpProfit[ k%2 ][l-1];
        
    }
};
