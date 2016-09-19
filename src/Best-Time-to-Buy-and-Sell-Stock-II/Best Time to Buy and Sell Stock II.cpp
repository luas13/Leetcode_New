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
