/*
// The idea is similar with "Find the subarray wich has the largest sum"
// 
// The only thing to note here is, maximum product can also be obtained by minimum (negative) product
// ending with the previous element multiplied by this element. For example, in array {12, 2, -3, -5, -6, -2},
// when we are at element -2, the maximum product is multiplication of, minimum product ending with -6 and -2.
// Thanks to Haoel
//

*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        
        // max/min product for previous and current position
        int max_prev= A[0];
        int max_here= A[0];
        int min_prev= A[0];
        int min_here= A[0];
        
        int max_prod= A[0];
        
        for(int i=1; i<n; i++)
        {
            max_here= max(  max( max_prev * A[i], min_prev * A[i] ) , A[i] );
            min_here= min(  min( max_prev * A[i], min_prev * A[i] ) , A[i] );
            
            max_prod= max( max_prod, max_here);
            
            max_prev= max_here;
            min_prev= min_here;
        }
        
        return max_prod;
    }
};
